$NetBSD: patch-src_mongo_util_intrusive__counter.h,v 1.1 2019/06/28 16:30:56 gdt Exp $

--- src/mongo/util/intrusive_counter.h.orig	2016-01-05 18:31:44.000000000 +0000
+++ src/mongo/util/intrusive_counter.h
@@ -28,6 +28,7 @@
 
 #pragma once
 
+#include <cstdlib>
 #include <boost/intrusive_ptr.hpp>
 #include <stdlib.h>
 
