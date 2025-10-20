$NetBSD: patch-compat__vis.c,v 1.1 2025/10/20 19:09:17 vins Exp $

Fix indeterminate use of pointer after realloc. 

--- compat_vis.c.orig	2025-10-20 17:18:46.766954133 +0000
+++ compat_vis.c
@@ -217,9 +217,9 @@ stravis(char **outp, const char *src, in
 		return -1;
 	len = strvis(buf, src, flag);
 	serrno = errno;
-	*outp = realloc(buf, len + 1);
-	if (*outp == NULL) {
-		*outp = buf;
+	outp = realloc(buf, len + 1);
+	if (outp == NULL) {
+		free(buf);
 		errno = serrno;
 	}
 	return (len);
