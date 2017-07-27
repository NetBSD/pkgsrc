$NetBSD: patch-src_rrd__restore.c,v 1.2 2017/07/27 18:31:20 adam Exp $

Use <ctype.h> correctly.

--- src/rrd_restore.c.orig	2017-05-16 12:26:46.000000000 +0000
+++ src/rrd_restore.c
@@ -104,7 +104,7 @@ static xmlChar* get_xml_element (
 		}
 		/* strip whitespace from end of message */
 		for (c-- ; c != msgcpy ; c--) {
-		    if (!isprint(*c)) {
+		    if (!isprint((unsigned char)*c)) {
 			*c = 0;
 		    }
 		}
