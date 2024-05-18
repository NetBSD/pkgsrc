$NetBSD: patch-src_libmissing_strlcpy.c,v 1.1 2024/05/18 22:31:06 bacon Exp $

# Use local strlcpy() without collision

--- src/libmissing/strlcpy.c.orig	2024-05-18 22:08:28.175772831 +0000
+++ src/libmissing/strlcpy.c
@@ -29,7 +29,7 @@ static char *rcsid = "$OpenBSD: strlcpy.
  * Returns strlen(src); if retval >= siz, truncation occurred.
  */
 size_t
-strlcpy(char *dst, const char *src, size_t siz)
+__munge_strlcpy(char *dst, const char *src, size_t siz)
 {
 	register char *d = dst;
 	register const char *s = src;
