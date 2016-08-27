$NetBSD: patch-src_rrd__restore.c,v 1.1 2016/08/27 07:40:23 dholland Exp $

Use <ctype.h> correctly.

--- src/rrd_restore.c~	2016-04-19 15:52:26.000000000 +0000
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
