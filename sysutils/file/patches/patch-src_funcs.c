$NetBSD: patch-src_funcs.c,v 1.1 2019/03/16 09:02:41 bsiegert Exp $

fix PR/62: spinpx: limit size of file_printable.  (CVE-2019-8904)

https://bugs.astron.com/view.php?id=62
https://github.com/file/file/commit/d65781527c8134a1202b2649695d48d5701ac60b

--- src/funcs.c.orig	2017-08-28 13:39:18.000000000 +0000
+++ src/funcs.c
@@ -581,12 +581,13 @@ file_pop_buffer(struct magic_set *ms, fi
  * convert string to ascii printable format.
  */
 protected char *
-file_printable(char *buf, size_t bufsiz, const char *str)
+file_printable(char *buf, size_t bufsiz, const char *str, size_t slen)
 {
-	char *ptr, *eptr;
+	char *ptr, *eptr = buf + bufsiz - 1;
 	const unsigned char *s = (const unsigned char *)str;
+	const unsigned char *es = s + slen;
 
-	for (ptr = buf, eptr = ptr + bufsiz - 1; ptr < eptr && *s; s++) {
+	for (ptr = buf;  ptr < eptr && s < es && *s; s++) {
 		if (isprint(*s)) {
 			*ptr++ = *s;
 			continue;
