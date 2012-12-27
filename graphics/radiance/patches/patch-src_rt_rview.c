$NetBSD: patch-src_rt_rview.c,v 1.1 2012/12/27 00:23:21 dholland Exp $

Pass around input buffer lengths.

--- src/rt/rview.c~	2004-09-08 01:47:43.000000000 +0000
+++ src/rt/rview.c
@@ -208,7 +208,7 @@ char  *prompt;
 	char  inpbuf[256];
 	char  *args;
 again:
-	(*dev->comin)(inpbuf, prompt);		/* get command + arguments */
+	(*dev->comin)(inpbuf, sizeof(inpbuf), prompt);		/* get command + arguments */
 	for (args = inpbuf; *args && *args != ' '; args++)
 		;
 	if (*args) *args++ = '\0';
