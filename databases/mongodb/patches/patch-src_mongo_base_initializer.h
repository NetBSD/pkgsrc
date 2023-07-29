$NetBSD: patch-src_mongo_base_initializer.h,v 1.4 2023/07/29 11:45:43 adam Exp $

Fixes at least SunOS.

--- src/mongo/base/initializer.h.orig	2023-06-29 13:37:52.000000000 +0000
+++ src/mongo/base/initializer.h
@@ -32,6 +32,7 @@
 #include <functional>
 #include <string>
 #include <vector>
+#include <unistd.h>
 
 #include "mongo/base/status.h"
 
