$NetBSD: patch-glib_genviron.c,v 1.1 2019/12/29 19:40:56 triaxx Exp $

Avoid the build failure with Clang on FreeBSD (see PR 54752).
Set environ as a weak symbol (thanks to Joerg).

--- glib/genviron.c.orig	2019-12-19 16:33:15.000000000 +0000
+++ glib/genviron.c
@@ -321,7 +321,11 @@ g_setenv (const gchar *variable,
 /* According to the Single Unix Specification, environ is not
  * in any system header, although unistd.h often declares it.
  */
+#if defined(__FreeBSD__)
+extern __attribute__((__weak__)) char **environ;
+#else
 extern char **environ;
+#endif
 #endif
 
 /**
