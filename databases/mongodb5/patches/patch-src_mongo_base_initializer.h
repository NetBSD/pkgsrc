$NetBSD: patch-src_mongo_base_initializer.h,v 1.1 2026/09/22 16:47:10 abs Exp $

Fixes at least SunOS.

--- src/mongo/base/initializer.h.orig	2025-12-22 22:01:16.000000000 +0000
+++ src/mongo/base/initializer.h
@@ -32,6 +32,7 @@
 #include <functional>
 #include <string>
 #include <vector>
+#include <unistd.h>
 
 #include "mongo/base/status.h"
 
