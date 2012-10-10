$NetBSD: patch-build_src_mn-pop3-mailbox.c,v 1.1 2012/10/10 19:39:57 markd Exp $

Fix complaint about Base64: overflowed buffer. 
Patch from Fedora. 

--- build/src/mn-pop3-mailbox.c.orig	2008-05-22 15:47:50.000000000 +0000
+++ build/src/mn-pop3-mailbox.c
@@ -742,7 +742,7 @@ mn_pop3_mailbox_enter_auth_cb (MNClientS
 
 	if (initial_clientoutlen > 0)
 	  {
-	    char buf64[initial_clientoutlen * 2]; /* Base64 is 33% larger than the data it encodes */
+	    char buf64[initial_clientoutlen * 2 + 1]; /* Base64 is 33% larger than the data it encodes */
 	    unsigned int outlen;
 	    int result;
 	    char *str;
