$NetBSD: patch-src_mongo_util_intrusive__counter.h,v 1.2 2016/02/12 03:37:24 ryoon Exp $

--- src/mongo/util/intrusive_counter.h.orig	2016-01-05 18:31:44.000000000 +0000
+++ src/mongo/util/intrusive_counter.h
@@ -28,6 +28,7 @@
 
 #pragma once
 
+#include <cstdlib>
 #include <boost/intrusive_ptr.hpp>
 #include <stdlib.h>
 
