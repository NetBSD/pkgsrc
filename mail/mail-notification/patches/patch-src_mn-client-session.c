$NetBSD: patch-src_mn-client-session.c,v 1.1 2012/10/10 19:39:57 markd Exp $

Fix complaint about Base64: overflowed buffer.
Patch from Fedora.

--- src/mn-client-session.c.orig	2008-05-22 15:45:35.000000000 +0000
+++ src/mn-client-session.c
@@ -1030,7 +1030,7 @@ mn_client_session_write (MNClientSession
 static int
 write_base64 (MNClientSession *session, const char *buf, unsigned int len)
 {
-  char buf64[len * 2];		/* Base64 is 33% larger than the data it encodes */
+  char buf64[len * 2 + 1];		/* Base64 is 33% larger than the data it encodes */
   unsigned int outlen;
   int result;
   char *str;
