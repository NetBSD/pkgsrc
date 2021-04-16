$NetBSD: patch-pxz.c,v 1.1 2021/04/16 16:16:05 ryoon Exp $

fixed complie error.
fixed CVE. 

cf. FreeBSD's ports
cf. Debian's deb fix CVE patch

--- pxz.c.orig	2019-05-07 15:08:53.000000000 +0000
+++ pxz.c
@@ -23,11 +23,17 @@
 
 #include <string.h>
 #include <stdio.h>
+#if !defined(__FreeBSD__) && !defined(__NetBSD__)
 #include <stdio_ext.h>
+#endif
 #include <stdlib.h>
 #include <inttypes.h>
 #include <unistd.h>
+#if defined(__FreeBSD__) || defined(__NetBSD__)
+#include <err.h>
+#else
 #include <error.h>
+#endif
 #include <errno.h>
 #include <sys/stat.h>
 #include <sys/mman.h>
@@ -42,6 +48,10 @@
 #include <omp.h>
 #endif
 
+#if defined(__FreeBSD__) || defined(__NetBSD__)
+#define error errc
+#endif
+
 #ifndef XZ_BINARY
 #define XZ_BINARY "xz"
 #endif
@@ -132,6 +142,13 @@ const struct option long_opts[] = {
 	{ NULL,             0,                 NULL,   0 }
 };
 
+#if defined(__FreeBSD__) || defined(__NetBSD__)
+static size_t __fpending (FILE *fp)
+{
+	return (fp->_p - fp->_bf._base);
+}
+#endif
+
 void __attribute__((noreturn)) run_xz( char **argv, char **envp ) {
 	execve(XZ_BINARY, argv, envp);
 	error(0, errno, "execution of "XZ_BINARY" binary failed");
