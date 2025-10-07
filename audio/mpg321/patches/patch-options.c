$NetBSD: patch-options.c,v 1.1 2025/10/07 03:56:02 mrg Exp $

Add missing type for remote_restart.


--- options.c.orig	2012-03-25 05:27:49.000000000 -0700
+++ options.c	2025-09-29 14:04:02.339936322 -0700
@@ -44,7 +44,7 @@
 extern char *proxy_server;
 extern int auth_enable;
 extern int auth_enable_var;
-extern remote_restart;
+extern int remote_restart;
 /*Basic Authentication Arguments*/
 char *basic_auth = NULL;
 
