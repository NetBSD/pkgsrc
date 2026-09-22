$NetBSD: patch-glib_gspawn-posix.c,v 1.2 2026/09/22 04:06:12 ryoon Exp $

Avoid the build failure with Clang on FreeBSD (see PR 54752).
Set environ as a weak symbol (thanks to Joerg).

--- glib/gspawn-posix.c.orig	2026-09-09 13:40:59.000000000 +0000
+++ glib/gspawn-posix.c
@@ -108,7 +108,11 @@
 #include <dlfcn.h>
 #define environ (*((char***)dlsym(RTLD_DEFAULT, "environ")))
 #else
+#if defined(__FreeBSD__) || defined(__DragonFly__)
+extern __attribute__((__weak__)) char **environ;
+#else
 extern char **environ;
+#endif
 #endif
 
 #ifndef O_CLOEXEC
