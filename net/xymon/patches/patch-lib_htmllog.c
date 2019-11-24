$NetBSD: patch-lib_htmllog.c,v 1.1 2019/11/24 20:16:55 spz Exp $

from https://sourceforge.net/p/xymon/code/8084/
Add guards around GCC diagnostics pragma to allow for building on older vers

--- lib/htmllog.c.orig	2019-07-23 14:46:51.000000000 +0000
+++ lib/htmllog.c
@@ -647,8 +647,10 @@ char *hostnamehtml(char *hostname, char 
 	 * else just put the hostname there.
 	 */
 
+#if __GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 6)
 	#pragma GCC diagnostic push
 	#pragma GCC diagnostic ignored "-Wformat-truncation"
+#endif  // __GNUC__
 	if (documentationurl) {
 		snprintf(result, sizeof(result), "<A HREF=\"%s\" %s><FONT %s>%s</FONT></A>",
 			urldoclink(documentationurl, hostname),
@@ -668,8 +670,10 @@ char *hostnamehtml(char *hostname, char 
 		snprintf(result, sizeof(result), "<FONT %s>%s</FONT>",
 			xgetenv("XYMONPAGEROWFONT"), nameandcomment(hinfo, hostname, usetooltip));
 	}
+#if __GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 6)
 	#pragma GCC diagnostic pop
 
+#endif  // __GNUC__
 	return result;
 }
 
