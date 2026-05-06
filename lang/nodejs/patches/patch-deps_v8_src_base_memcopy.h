$NetBSD: patch-deps_v8_src_base_memcopy.h,v 1.1 2026/05/06 08:21:01 adam Exp $

Add missing include for CHAR_BIT.
https://github.com/nodejs/node/issues/63146

--- deps/v8/src/base/memcopy.h.orig	2026-05-06 07:22:58.678410124 +0000
+++ deps/v8/src/base/memcopy.h
@@ -5,6 +5,7 @@
 #ifndef V8_BASE_MEMCOPY_H_
 #define V8_BASE_MEMCOPY_H_
 
+#include <climits>
 #include <stdlib.h>
 
 #include <atomic>
