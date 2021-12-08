$NetBSD: patch-src_closures.c,v 1.5 2021/12/08 08:20:17 adam Exp $

provide stub of ffi_data_to_code_pointer to get aarch64 to link

--- src/closures.c.orig	2021-06-27 18:03:12.000000000 +0000
+++ src/closures.c
@@ -38,6 +38,7 @@
 
 #ifdef __NetBSD__
 #include <sys/param.h>
+#include <err.h>
 #endif
 
 #if __NetBSD_Version__ - 0 >= 799007200
@@ -119,6 +120,14 @@ ffi_tramp_is_present (__attribute__((unu
 {
   return 0;
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
