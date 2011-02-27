$NetBSD: patch-string.c,v 1.1.2.2 2011/02/27 00:26:23 tron Exp $

* Import r30779 from repository.

--- string.c.orig	2010-12-20 13:22:53.000000000 +0000
+++ string.c
@@ -1483,7 +1483,7 @@ rb_str_offset(VALUE str, long pos)
 static char *
 str_utf8_nth(const char *p, const char *e, long nth)
 {
-    if ((int)SIZEOF_VALUE < e - p && (int)SIZEOF_VALUE * 2 < nth) {
+    if ((int)SIZEOF_VALUE * 2 < e - p && (int)SIZEOF_VALUE * 2 < nth) {
 	const VALUE *s, *t;
 	const VALUE lowbits = sizeof(VALUE) - 1;
 	s = (const VALUE*)(~lowbits & ((VALUE)p + lowbits));
