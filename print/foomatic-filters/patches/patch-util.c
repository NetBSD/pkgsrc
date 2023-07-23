$NetBSD: patch-util.c,v 1.1 2023/07/23 10:17:23 bsiegert Exp $

Use HAVE_STRLCPY and HAVE_STRLCAT.

--- util.c.orig	2012-07-02 14:50:46.000000000 +0000
+++ util.c
@@ -163,7 +163,7 @@ strcasestr (const char *haystack, const
 }
 #endif
 
-#ifndef __OpenBSD__
+#ifndef HAVE_STRLCPY
 size_t strlcpy(char *dest, const char *src, size_t size)
 {
     char *pdest = dest;
@@ -182,7 +182,9 @@ size_t strlcpy(char *dest, const char *s
         while (*psrc++);
     return (psrc - src -1);
 }
+#endif /* ! HAVE_STRLCPY */
 
+#ifndef HAVE_STRLCAT
 size_t strlcat(char *dest, const char *src, size_t size)
 {
     char *pdest = dest;
@@ -203,7 +205,7 @@ size_t strlcat(char *dest, const char *s
 
     return len + (psrc - src);
 }
-#endif /* ! __OpenBSD__ */
+#endif /* ! HAVE_STRLCAT */
 
 void strrepl(char *str, const char *chars, char repl)
 {
