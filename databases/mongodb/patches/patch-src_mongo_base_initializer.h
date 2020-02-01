$NetBSD: patch-src_mongo_base_initializer.h,v 1.3 2020/02/01 20:00:08 adam Exp $

Fixes at least SunOS.

--- src/mongo/base/initializer.h.orig	2019-12-04 23:29:59.000000000 +0000
+++ src/mongo/base/initializer.h
@@ -31,6 +31,7 @@
 
 #include <string>
 #include <vector>
+#include <unistd.h>
 
 #include "mongo/base/initializer_context.h"
 #include "mongo/base/initializer_dependency_graph.h"
