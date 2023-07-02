$NetBSD: patch-core_khronos_GL4_gl3w.c,v 1.1 2023/07/02 17:32:30 nia Exp $

libGL.so may have a different soname on NetBSD depending on whether
it is installed from pkgsrc or xbase.

--- core/khronos/GL4/gl3w.c.orig	2023-02-15 17:59:44.000000000 +0000
+++ core/khronos/GL4/gl3w.c
@@ -115,7 +115,11 @@ static GL3WglProc (*glx_get_proc_address
 
 static int open_libgl(void)
 {
+#ifdef __NetBSD__
+	libgl = dlopen("libGL.so", RTLD_LAZY | RTLD_LOCAL);
+#else
 	libgl = dlopen("libGL.so.1", RTLD_LAZY | RTLD_LOCAL);
+#endif
 	if (!libgl)
 		return GL3W_ERROR_LIBRARY_OPEN;
 
