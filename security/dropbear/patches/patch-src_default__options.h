$NetBSD: patch-src_default__options.h,v 1.1 2024/04/04 12:13:28 wiz Exp $

comment out the path to the dropbear ssh client
- this is passed through CFLAGS

--- src/default_options.h.orig	2024-04-04 14:30:00.000000000 +0000
+++ src/default_options.h
@@ -324,7 +324,7 @@ group1 in Dropbear server too */
 
 /* This is used by the scp binary when used as a client binary. If you're
  * not using the Dropbear client, you'll need to change it */
-#define DROPBEAR_PATH_SSH_PROGRAM "/usr/bin/dbclient"
+/*#define DROPBEAR_PATH_SSH_PROGRAM "/usr/bin/dbclient"*/
 
 /* Whether to log commands executed by a client. This only logs the
  * (single) command sent to the server, not what a user did in a
