$NetBSD: patch-src_common_jstream.h,v 1.1 2025/07/27 08:34:05 wiz Exp $

https://github.com/soramimi/Guitar/commit/ad88334a0ba555585ea653924fb749c5805d9aa1

--- src/common/jstream.h.orig	2025-07-21 19:46:10.990061174 +0000
+++ src/common/jstream.h
@@ -1560,7 +1560,7 @@ struct Object {
 
 static inline bool is_null(Variant const &v)
 {
-	return std::holds_alternative<nullptr_t>(v);
+	return std::holds_alternative<null_t>(v);
 }
 static inline bool is_boolean(Variant const &v)
 {
