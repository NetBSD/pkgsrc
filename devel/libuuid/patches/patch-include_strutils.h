$NetBSD: patch-include_strutils.h,v 1.1 2015/11/27 14:57:35 jperkin Exp $

Remove strmode declaration, libuuid doesn't use it and it conflicts
with Darwin's native strmode(3).

--- include/strutils.h.orig	2015-10-06 06:59:51.000000000 +0000
+++ include/strutils.h
@@ -78,7 +78,6 @@ static inline char *strdup_to_offset(voi
 #define strdup_to_struct_member(_s, _m, _str) \
 		strdup_to_offset((void *) _s, offsetof(__typeof__(*(_s)), _m), _str)
 
-extern void strmode(mode_t mode, char *str);
 
 /* Options for size_to_human_string() */
 enum
