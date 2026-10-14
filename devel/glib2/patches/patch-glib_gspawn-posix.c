$NetBSD: patch-glib_gspawn-posix.c,v 1.3 2026/10/14 09:34:25 jperkin Exp $

Avoid the build failure with Clang on FreeBSD (see PR 54752).
Set environ as a weak symbol (thanks to Joerg).

--- glib/gspawn-posix.c.orig	2026-10-06 15:22:44.000000000 +0000
+++ glib/gspawn-posix.c
@@ -108,8 +108,12 @@
 #include <dlfcn.h>
 #define environ (*((char***)dlsym(RTLD_DEFAULT, "environ")))
 #else
+#if defined(__FreeBSD__) || defined(__DragonFly__)
+extern __attribute__((__weak__)) char **environ;
+#else
 extern char **environ;
 #endif
+#endif
 
 #ifndef O_CLOEXEC
 #define O_CLOEXEC 0
