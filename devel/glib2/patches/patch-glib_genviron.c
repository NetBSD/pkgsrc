$NetBSD: patch-glib_genviron.c,v 1.3 2024/04/01 23:43:13 charlotte Exp $

Avoid the build failure with Clang on FreeBSD (see PR 54752).
Set environ as a weak symbol (thanks to Joerg).

--- glib/genviron.c.orig	2020-02-27 16:12:52.000000000 +0000
+++ glib/genviron.c
@@ -329,8 +329,12 @@ g_setenv (const gchar *variable,
 /* According to the Single Unix Specification, environ is not
  * in any system header, although unistd.h often declares it.
  */
+#if defined(__FreeBSD__) || defined(__DragonFly__)
+extern __attribute__((__weak__)) char **environ;
+#else
 extern char **environ;
 #endif
+#endif
 
 /**
  * g_unsetenv:
