$NetBSD: patch-common__func.h,v 1.1 2024/10/16 07:37:04 nia Exp $

Fix build with GCC before 10.

--- common_func.h.orig	2024-10-16 07:30:15.066490418 +0000
+++ common_func.h
@@ -142,6 +142,10 @@ wchar_t* rhash_wcsdup(const wchar_t* str
 #define rsh_tstrdup(str) rsh_strdup(str)
 #endif
 
+#ifndef __has_builtin
+#define __has_builtin(x) 0
+#endif
+
 /* get_ctz - count traling zero bits */
 #if (defined(__GNUC__) && (__GNUC__ > 3 || (__GNUC__ == 3 && __GNUC_MINOR__ >= 4))) || \
     (defined(__clang__) && __has_builtin(__builtin_ctz))
