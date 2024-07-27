$NetBSD: patch-ext_bifrost_src_libpopcnt.h,v 1.2 2024/07/27 12:22:54 bacon Exp $

# Use native popcnt

--- ext/bifrost/src/libpopcnt.h.orig	2023-07-24 12:34:08.037669065 +0000
+++ ext/bifrost/src/libpopcnt.h
@@ -32,6 +32,8 @@
 #ifndef LIBPOPCNT_H
 #define LIBPOPCNT_H
 
+#ifndef __NetBSD__
+
 #include <stdint.h>
 
 #ifndef __has_builtin
@@ -584,4 +586,6 @@ static inline uint64_t popcnt(const void
 
 #endif
 
+#endif /* NetBSD */
+
 #endif /* LIBPOPCNT_H */
