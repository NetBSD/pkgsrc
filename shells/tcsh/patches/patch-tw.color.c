$NetBSD: patch-tw.color.c,v 1.1 2021/11/14 22:15:13 kim Exp $

Fix the ln=target code by NUL terminating the result of readlink(2).

https://github.com/tcsh-org/tcsh/commit/247a7d6649621fdc40c31ad81c4967413213b9d2.patch

--- tw.color.c
+++ tw.color.c
@@ -482,10 +482,12 @@ print_with_color(const Char *filename, size_t len, Char suffix)
 	    char buf[MAXPATHLEN];
 
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
