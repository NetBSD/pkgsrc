$NetBSD: patch-glib_gspawn.c,v 1.3 2024/04/01 23:43:13 charlotte Exp $

Avoid the build failure with Clang on FreeBSD (see PR 54752).
Set environ as a weak symbol (thanks to Joerg).

--- glib/gspawn.c.orig	2020-02-27 16:12:52.000000000 +0000
+++ glib/gspawn.c
@@ -85,8 +85,12 @@
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
