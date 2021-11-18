$NetBSD: patch-tw.color.c,v 1.2 2021/11/18 10:20:47 kim Exp $

Fix the ln=target code by NUL terminating the result of readlink(2).
Fix off-by-one, found by Coverity

https://github.com/tcsh-org/tcsh/commit/247a7d6649621fdc40c31ad81c4967413213b9d2.patch
https://github.com/tcsh-org/tcsh/commit/92e557e324655906b73bad5253885051bbb7162e.patch

--- tw.color.c.orig	2021-11-11 09:54:05.000000000 +0000
+++ tw.color.c	2021-11-18 09:54:30.997940824 +0000
@@ -479,13 +479,15 @@
 	if (suffix == '@' && color_as_referent) {
 	    char *f = short2str(filename);
 	    Char c = suffix;
-	    char buf[MAXPATHLEN];
+	    char buf[MAXPATHLEN + 1];
 
 	    while (c == '@') {
-		if (readlink(f, buf, MAXPATHLEN) == -1) {
+		ssize_t b = readlink(f, buf, MAXPATHLEN);
+		if (b == -1) {
 		    c = '&';
 		    break;
 		}
+		buf[b] = '\0';
 
 		c = filetype(STRNULL, str2short(buf));
 		f = buf;
