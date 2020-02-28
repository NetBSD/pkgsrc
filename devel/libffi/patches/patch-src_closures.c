$NetBSD: patch-src_closures.c,v 1.4 2020/02/28 18:14:28 tnn Exp $

provide stub of ffi_data_to_code_pointer to get aarch64 to link

--- src/closures.c.orig	2019-11-20 11:15:41.000000000 +0000
+++ src/closures.c
@@ -37,6 +37,7 @@
 
 #ifdef __NetBSD__
 #include <sys/param.h>
+#include <err.h>
 #endif
 
 #if __NetBSD_Version__ - 0 >= 799007200
@@ -109,6 +110,14 @@ ffi_closure_free (void *ptr)
   munmap(dataseg, rounded_size);
   munmap(codeseg, rounded_size);
 }
+
+void *
+ffi_data_to_code_pointer (void *data)
+{
+  errx(1, "ffi_data_to_code_pointer: not implemented");
+  return NULL;
+}
+
 #else /* !NetBSD with PROT_MPROTECT */
 
 #if !FFI_MMAP_EXEC_WRIT && !FFI_EXEC_TRAMPOLINE_TABLE
