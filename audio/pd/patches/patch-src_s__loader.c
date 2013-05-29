$NetBSD: patch-src_s__loader.c,v 1.4 2013/05/29 11:26:12 wiz Exp $

Define extensions for NetBSD.
https://sourceforge.net/tracker/?func=detail&aid=3411732&group_id=55736&atid=478072

Define extensions for OpenBSD.

Define extensions for Solaris.

--- src/s_loader.c.orig	2010-07-29 03:50:34.000000000 +0000
+++ src/s_loader.c
@@ -38,6 +38,24 @@ a fat binary or an indication of the ins
 
 #ifdef __FreeBSD__
 static char sys_dllextent[] = ".b_i386", sys_dllextent2[] = ".pd_freebsd";
+#elif defined(__NetBSD__)
+# ifdef __x86_64__
+static char sys_dllextent[] = ".n_ia64", sys_dllextent2[] = ".pd_netbsd";
+# else
+static char sys_dllextent[] = ".n_i386", sys_dllextent2[] = ".pd_netbsd";
+# endif
+#elif defined(__OpenBSD__)
+# ifdef __x86_64__
+static char sys_dllextent[] = ".b_ia64", sys_dllextent2[] = ".pd_openbsd";
+# else
+static char sys_dllextent[] = ".b_i386", sys_dllextent2[] = ".pd_openbsd";
+# endif
+#elif defined(__sun)
+# ifdef __x86_64__
+static char sys_dllextent[] = ".s_ia64", sys_dllextent2[] = ".pd_sunos";
+# elif __i386__
+static char sys_dllextent[] = ".s_i386", sys_dllextent2[] = ".pd_sunos";
+# endif
 #elif defined(__linux__) || defined(__FreeBSD_kernel__) || defined(__GNU__)
 # ifdef __x86_64__
 static char sys_dllextent[] = ".l_ia64", sys_dllextent2[] = ".pd_linux";
