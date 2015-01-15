$NetBSD: patch-tools_gpgkey2ssh.c,v 1.1 2015/01/15 20:59:59 wiz Exp $

Fix executable name.

--- tools/gpgkey2ssh.c.orig	2014-08-11 21:43:41.000000000 +0000
+++ tools/gpgkey2ssh.c
@@ -266,7 +266,7 @@ main (int argc, char **argv)
   keyid = argv[1];
 
   ret = asprintf (&command,
-		  "gpg --list-keys --with-colons --with-key-data '%s'",
+		  "gpg2 --list-keys --with-colons --with-key-data '%s'",
 		  keyid);
   assert (ret > 0);
 
