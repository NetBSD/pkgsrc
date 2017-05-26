$NetBSD: patch-src_closures.c,v 1.1 2017/05/26 18:55:41 joerg Exp $

--- src/closures.c.orig	2017-05-22 23:16:12.516083134 +0000
+++ src/closures.c
@@ -33,6 +33,83 @@
 #include <ffi.h>
 #include <ffi_common.h>
 
+#ifdef __NetBSD__
+#include <sys/param.h>
+#endif
+
+#if __NetBSD_Version__ - 0 >= 799007200
+/* NetBSD with PROT_MPROTECT */
+#include <sys/mman.h>
+
+#include <stddef.h>
+#include <unistd.h>
+
+static const size_t overhead =
+  (sizeof(max_align_t) > sizeof(void *) + sizeof(size_t)) ?
+    sizeof(max_align_t)
+    : sizeof(void *) + sizeof(size_t);
+
+#define ADD_TO_POINTER(p, d) ((void *)((uintptr_t)(p) + (d)))
+
+void *
+ffi_closure_alloc (size_t size, void **code)
+{
+  static size_t page_size;
+  size_t rounded_size;
+  void *codeseg, *dataseg;
+  int prot;
+  
+
+  /* Expect that PAX mprotect is active and a separate code mapping is necessary. */
+  if (!code)
+    return NULL;
+
+  /* Obtain system page size. */
+  if (!page_size)
+    page_size = sysconf(_SC_PAGESIZE);
+
+  /* Round allocation size up to the next page, keeping in mind the size field and pointer to code map. */
+  rounded_size = (size + overhead + page_size - 1) & ~(page_size - 1);
+
+  /* Primary mapping is RW, but request permission to switch to PROT_EXEC later. */
+  prot = PROT_READ | PROT_WRITE | PROT_MPROTECT(PROT_EXEC);
+  dataseg = mmap(NULL, rounded_size, prot, MAP_ANON | MAP_PRIVATE, -1, 0);
+  if (dataseg == MAP_FAILED)
+    return NULL;
+
+  /* Create secondary mapping and switch it to RX. */
+  codeseg = mremap(dataseg, rounded_size, NULL, rounded_size, MAP_REMAPDUP);
+  if (codeseg == MAP_FAILED) {
+    munmap(dataseg, rounded_size);
+    return NULL;
+  }
+  if (mprotect(codeseg, rounded_size, PROT_READ | PROT_EXEC) == -1) {
+    munmap(codeseg, rounded_size);
+    munmap(dataseg, rounded_size);
+    return NULL;
+  }
+
+  /* Remember allocation size and location of the secondary mapping for ffi_closure_free. */
+  memcpy(dataseg, &rounded_size, sizeof(rounded_size));
+  memcpy(ADD_TO_POINTER(dataseg, sizeof(size_t)), &codeseg, sizeof(void *));
+  *code = ADD_TO_POINTER(codeseg, overhead);
+  return ADD_TO_POINTER(dataseg, overhead);
+}
+
+void
+ffi_closure_free (void *ptr)
+{
+  void *codeseg, *dataseg;
+  size_t rounded_size;
+
+  dataseg = ADD_TO_POINTER(ptr, overhead);
+  memcpy(&rounded_size, dataseg, sizeof(rounded_size));
+  memcpy(&codeseg, ADD_TO_POINTER(dataseg, sizeof(size_t)), sizeof(void *));
+  munmap(dataseg, rounded_size);
+  munmap(codeseg, rounded_size);
+}
+#else /* !NetBSD with PROT_MPROTECT */
+
 #if !FFI_MMAP_EXEC_WRIT && !FFI_EXEC_TRAMPOLINE_TABLE
 # if __gnu_linux__ && !defined(__ANDROID__)
 /* This macro indicates it may be forbidden to map anonymous memory
@@ -686,3 +763,5 @@ ffi_closure_free (void *ptr)
 
 # endif /* ! FFI_MMAP_EXEC_WRIT */
 #endif /* FFI_CLOSURES */
+
+#endif /* NetBSD with PROT_MPROTECT */
