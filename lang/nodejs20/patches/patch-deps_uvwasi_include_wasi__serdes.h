$NetBSD: patch-deps_uvwasi_include_wasi__serdes.h,v 1.1 2023/11/02 13:16:54 adam Exp $

NetBSD<9 used to have #define uint8_t etc. which caused issues with complicated
defines like this one.

--- deps/uvwasi/include/wasi_serdes.h.orig	2020-08-11 14:32:04.000000000 +0000
+++ deps/uvwasi/include/wasi_serdes.h
@@ -3,6 +3,13 @@
 
 #include "wasi_types.h"
 
+#ifdef __NetBSD__
+#undef uint8_t
+#undef uint16_t
+#undef uint32_t
+#undef uint64_t
+#endif
+
 /* Basic uint{8,16,32,64}_t read/write functions. */
 
 #define BASIC_TYPE(name, type)                                                \
