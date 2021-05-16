$NetBSD: patch-unix_vncserver_vncsession.c,v 1.1 2021/05/16 21:06:43 wiz Exp $

--- unix/vncserver/vncsession.c.orig	2020-09-08 12:16:08.000000000 +0000
+++ unix/vncserver/vncsession.c
@@ -37,6 +37,10 @@
 #include <sys/types.h>
 #include <sys/wait.h>
 
+#ifndef HOST_NAME_MAX
+#define HOST_NAME_MAX 255
+#endif
+
 extern char **environ;
 
 // PAM service name
