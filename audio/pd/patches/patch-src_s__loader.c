$NetBSD: patch-src_s__loader.c,v 1.1.1.1 2011/09/15 01:05:05 wiz Exp $

Define extensions for NetBSD.

--- src/s_loader.c.orig	2010-07-29 03:50:34.000000000 +0000
+++ src/s_loader.c
@@ -38,6 +38,12 @@ a fat binary or an indication of the ins
 
 #ifdef __FreeBSD__
 static char sys_dllextent[] = ".b_i386", sys_dllextent2[] = ".pd_freebsd";
+#elif defined(__NetBSD__)
+# ifdef __x86_64__
+static char sys_dllextent[] = ".n_ia64", sys_dllextent2[] = ".pd_netbsd";
+# else
+static char sys_dllextent[] = ".n_i386", sys_dllextent2[] = ".pd_netbsd";
+# endif
 #elif defined(__linux__) || defined(__FreeBSD_kernel__) || defined(__GNU__)
 # ifdef __x86_64__
 static char sys_dllextent[] = ".l_ia64", sys_dllextent2[] = ".pd_linux";
