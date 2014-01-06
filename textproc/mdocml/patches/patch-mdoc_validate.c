$NetBSD: patch-mdoc_validate.c,v 1.1 2014/01/06 17:43:50 tez Exp $

Solaris, Mingw32 & OS X prior to 10.7 are missing strnlen


--- mdoc_validate.c.orig	Mon Jan  6 10:25:04 2014
+++ mdoc_validate.c	Mon Jan  6 10:36:31 2014
@@ -1863,6 +1863,15 @@
 	return(1);
 }
 
+#if defined(__MINGW32__) ||defined(__sun) || defined(__APPLE__)
+static size_t p_strnlen(const char *s, size_t maxlen) {
+  const char *end = memchr(s, 0, maxlen);
+  return end ? (size_t)(end - s) : maxlen;
+}
+#else
+ # define p_strnlen strnlen
+#endif
+
 /*
  * For some arguments of some macros,
  * convert all breakable hyphens into ASCII_HYPH.
@@ -1893,7 +1902,7 @@
 		if (MDOC_TEXT != nch->type)
 			continue;
 		cp = nch->string;
-		if (3 > strnlen(cp, 3))
+		if (3 > p_strnlen(cp, 3))
 			continue;
 		while ('\0' != *(++cp))
 			if ('-' == *cp &&
