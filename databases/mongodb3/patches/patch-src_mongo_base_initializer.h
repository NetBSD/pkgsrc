$NetBSD: patch-src_mongo_base_initializer.h,v 1.1 2019/06/28 16:30:56 gdt Exp $

Fixes at least SunOS.
--- src/mongo/base/initializer.h.orig	2014-04-07 00:36:57.000000000 +0000
+++ src/mongo/base/initializer.h
@@ -17,6 +17,7 @@
 
 #include <string>
 #include <vector>
+#include <unistd.h>
 
 #include "mongo/base/disallow_copying.h"
 #include "mongo/base/initializer_context.h"
