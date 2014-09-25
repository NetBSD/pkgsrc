$NetBSD: patch-parse.y,v 1.1.2.2 2014/09/25 18:08:56 spz Exp $

Fix for CVE-2014-7169 taken from here:

http://www.openwall.com/lists/oss-security/2014/09/25/10

--- parse.y.orig	2014-09-25 14:24:07.000000000 +0100
+++ parse.y	2014-09-25 14:25:05.000000000 +0100
@@ -2953,6 +2953,8 @@
   FREE (word_desc_to_read);
   word_desc_to_read = (WORD_DESC *)NULL;
 
+  eol_ungetc_lookahead = 0;
+
   current_token = '\n';		/* XXX */
   last_read_token = '\n';
   token_to_read = '\n';
