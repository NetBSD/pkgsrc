$NetBSD: patch-core_deps_khronos_GL4_gl3w.c,v 1.1 2023/11/17 09:27:51 nia Exp $

Support OpenGL on NetBSD - so version differs between xsrc and pkgsrc.

--- core/deps/khronos/GL4/gl3w.c.orig	2023-10-27 22:19:54.000000000 +0000
+++ core/deps/khronos/GL4/gl3w.c
@@ -115,7 +115,7 @@ static GL3WglProc (*glx_get_proc_address
 
 static int open_libgl(void)
 {
-#if defined(__OpenBSD__)
+#if defined(__OpenBSD__) || defined(__NetBSD__)
 	libgl = dlopen("libGL.so", RTLD_LAZY | RTLD_LOCAL);
 #else
 	libgl = dlopen("libGL.so.1", RTLD_LAZY | RTLD_LOCAL);
