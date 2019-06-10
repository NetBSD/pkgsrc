$NetBSD: patch-default__options.h,v 1.1 2019/06/10 13:44:35 nia Exp $

comment out the path to the dropbear ssh client
- this is passed through CFLAGS

--- default_options.h.orig	2019-03-27 14:15:23.000000000 +0000
+++ default_options.h
@@ -259,7 +259,7 @@ Homedir is prepended unless path begins 
 
 /* This is used by the scp binary when used as a client binary. If you're
  * not using the Dropbear client, you'll need to change it */
-#define DROPBEAR_PATH_SSH_PROGRAM "/usr/bin/dbclient"
+/*#define DROPBEAR_PATH_SSH_PROGRAM "/usr/bin/dbclient"*/
 
 /* Whether to log commands executed by a client. This only logs the 
  * (single) command sent to the server, not what a user did in a 
