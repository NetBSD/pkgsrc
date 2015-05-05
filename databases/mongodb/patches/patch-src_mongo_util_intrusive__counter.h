$NetBSD: patch-src_mongo_util_intrusive__counter.h,v 1.1 2015/05/05 15:54:49 joerg Exp $

--- src/mongo/util/intrusive_counter.h.orig	2015-05-05 12:50:27.000000000 +0000
+++ src/mongo/util/intrusive_counter.h
@@ -28,6 +28,7 @@
 
 #pragma once
 
+#include <cstdlib>
 #include <boost/intrusive_ptr.hpp>
 #include <boost/noncopyable.hpp>
 #include "mongo/platform/atomic_word.h"
