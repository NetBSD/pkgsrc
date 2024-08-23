$NetBSD: patch-src_compile__cache.cc,v 1.1 2024/08/23 10:10:35 adam Exp $

Include unistd.h for getuid().

--- src/compile_cache.cc.orig	2024-08-23 09:02:08.124809520 +0000
+++ src/compile_cache.cc
@@ -1,5 +1,6 @@
 #include "compile_cache.h"
 #include <string>
+#include <unistd.h>
 #include "debug_utils-inl.h"
 #include "env-inl.h"
 #include "node_file.h"
