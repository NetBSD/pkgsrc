$NetBSD: patch-src_cache.h,v 1.1 2022/08/16 12:12:03 tnn Exp $

https://github.com/doxygen/doxygen/commit/5198966c8d5fec89116d025c74934ac03ea511fa

--- src/cache.h.orig	2022-04-28 17:56:07.000000000 +0000
+++ src/cache.h
@@ -19,6 +19,7 @@
 #include <list>
 #include <unordered_map>
 #include <mutex>
+#include <utility>
 #include <ctype.h>
 
 /*! Fixed size cache for value type V using keys of type K.
