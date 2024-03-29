$NetBSD: patch-src_mongo_base_initializer.h,v 1.1 2023/07/29 11:51:15 adam Exp $

Fixes at least SunOS.

--- src/mongo/base/initializer.h.orig	2019-12-04 23:29:59.000000000 +0000
+++ src/mongo/base/initializer.h
@@ -31,6 +31,7 @@
 
 #include <string>
 #include <vector>
+#include <unistd.h>
 
 #include "mongo/base/initializer_context.h"
 #include "mongo/base/initializer_dependency_graph.h"
