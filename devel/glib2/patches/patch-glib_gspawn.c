$NetBSD: patch-glib_gspawn.c,v 1.1 2019/12/29 19:40:56 triaxx Exp $

Avoid the build failure with Clang on FreeBSD (see PR 54752).
Set environ as a weak symbol (thanks to Joerg).

--- glib/gspawn.c.orig	2019-12-19 16:33:15.000000000 +0000
+++ glib/gspawn.c
@@ -85,7 +85,11 @@
 #ifdef HAVE__NSGETENVIRON
 #define environ (*_NSGetEnviron())
 #else
+#if defined(__FreeBSD__)
+extern __attribute__((__weak__)) char **environ;
+#else
 extern char **environ;
+#endif
 #endif
 
 #ifndef O_CLOEXEC
