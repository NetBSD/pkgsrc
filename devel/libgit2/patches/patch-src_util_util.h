$NetBSD: patch-src_util_util.h,v 1.3 2024/04/05 17:03:59 wiz Exp $

Ensure appropriate value range for arg to tolower().

--- src/util/util.h.orig	2023-04-12 12:05:25.000000000 +0000
+++ src/util/util.h
@@ -89,7 +89,7 @@ GIT_INLINE(int) git__tolower(int c)
 	return (c >= 'A' && c <= 'Z') ? (c + 32) : c;
 }
 #else
-# define git__tolower(a) tolower(a)
+# define git__tolower(a) tolower((unsigned char)a)
 #endif
 
 extern size_t git__linenlen(const char *buffer, size_t buffer_len);
