$NetBSD: patch-maa_log.c,v 1.1 2020/06/16 12:40:23 leot Exp $

MAXHOSTNAMELEN can be already defined, limit to 64 characters to avoid
possible truncation.

--- maa/log.c.orig	2020-04-10 22:10:13.000000000 +0000
+++ maa/log.c
@@ -314,7 +314,7 @@ static void _log_base_va(
 			buf_preamble [0] = 0;
 		} else {
 			snprintf (buf_preamble, sizeof (buf_preamble),
-					  "%24.24s %s %s[%ld]: ",
+					  "%24.24s %.64s %s[%ld]: ",
 					  ctime(&t),
 					  logHostname,
 					  logIdent,
