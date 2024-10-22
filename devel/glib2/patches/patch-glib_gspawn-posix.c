$NetBSD: patch-glib_gspawn-posix.c,v 1.1 2024/10/22 09:50:39 adam Exp $

Avoid the build failure with Clang on FreeBSD (see PR 54752).
Set environ as a weak symbol (thanks to Joerg).

--- glib/gspawn-posix.c.orig	2024-10-17 11:08:41.000000000 +0000
+++ glib/gspawn-posix.c
@@ -101,8 +101,12 @@
 #ifdef HAVE__NSGETENVIRON
 #define environ (*_NSGetEnviron())
 #else
+#if defined(__FreeBSD__) || defined(__DragonFly__)
+extern __attribute__((__weak__)) char **environ;
+#else
 extern char **environ;
 #endif
+#endif
 
 #ifndef O_CLOEXEC
 #define O_CLOEXEC 0
