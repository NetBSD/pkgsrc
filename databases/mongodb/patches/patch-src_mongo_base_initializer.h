$NetBSD: patch-src_mongo_base_initializer.h,v 1.2 2019/03/05 19:35:58 adam Exp $

Fixes at least SunOS.

--- src/mongo/base/initializer.h.orig	2019-01-30 14:26:33.000000000 +0000
+++ src/mongo/base/initializer.h
@@ -32,6 +32,7 @@
 
 #include <string>
 #include <vector>
+#include <unistd.h>
 
 #include "mongo/base/disallow_copying.h"
 #include "mongo/base/initializer_context.h"
