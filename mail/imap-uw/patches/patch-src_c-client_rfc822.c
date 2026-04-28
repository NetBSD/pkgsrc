$NetBSD: patch-src_c-client_rfc822.c,v 1.1 2026/04/28 19:35:39 vins Exp $

Make sure we don't get an overflow for messages on \015. 

--- src/c-client/rfc822.c.orig	2011-07-23 00:20:18.000000000 +0000
+++ src/c-client/rfc822.c
@@ -384,6 +384,8 @@ void rfc822_parse_content (BODY *body,ST
 	if (CHR (bs) == '\012'){/* following LF? */
 	  c = SNX (bs); i--;	/* yes, slurp it */
 	}
+	if (!i)
+	  break;
       case '\012':		/* at start of a line, start with -- ? */
 	if (!(i && i-- && ((c = SNX (bs)) == '-') && i-- &&
 	      ((c = SNX (bs)) == '-'))) break;
