$NetBSD: patch-source_core_slang-hash.h,v 1.1 2026/09/24 18:41:26 ktnb Exp $

unordered-dense doesn't have slang's special wyhash::hash use the
traditional hash_bytes instead.

--- source/core/slang-hash.h.orig	2026-09-23 15:08:07.633837148 +0000
+++ source/core/slang-hash.h
@@ -135,7 +135,7 @@ inline HashCode64 getHashCode(const char* buffer, std:
 
 inline HashCode64 getHashCode(const char* buffer, std::size_t len)
 {
-    return ankerl::unordered_dense::detail::wyhash::hash(buffer, len);
+    return ankerl::unordered_dense::detail::hash_bytes(buffer, len);
 }
 
 template<typename T>
