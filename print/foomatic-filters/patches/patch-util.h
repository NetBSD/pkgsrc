$NetBSD: patch-util.h,v 1.1 2023/07/23 10:17:23 bsiegert Exp $

Use HAVE_STRLCPY and HAVE_STRLCAT.

--- util.h.orig	2012-07-02 14:50:46.000000000 +0000
+++ util.h
@@ -70,8 +70,12 @@ char * strcasestr (const char *haystack,
 /* Copy at most size-1 characters from src to dest
    dest will always be \0 terminated (unless size == 0)
    returns strlen(src) */
+#ifndef HAVE_STRLCPY
 size_t strlcpy(char *dest, const char *src, size_t size);
+#endif
+#ifndef HAVE_STRLCAT
 size_t strlcat(char *dest, const char *src, size_t size);
+#endif
 
 /* Replace all occurences of each of the characters in 'chars' by 'repl' */
 void strrepl(char *str, const char *chars, char repl);
