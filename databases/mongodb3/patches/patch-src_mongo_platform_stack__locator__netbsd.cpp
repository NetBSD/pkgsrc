$NetBSD: patch-src_mongo_platform_stack__locator__netbsd.cpp,v 1.2 2019/07/09 07:28:30 adam Exp $

Add NetBSD support.

--- src/mongo/platform/stack_locator_netbsd.cpp.orig	2019-07-08 19:30:20.000000000 +0000
+++ src/mongo/platform/stack_locator_netbsd.cpp
@@ -31,7 +31,6 @@
 #include "mongo/platform/stack_locator.h"
 
 #include <pthread.h>
-#include <pthread_np.h>
 
 #include "mongo/util/assert_util.h"
 #include "mongo/util/scopeguard.h"
@@ -51,7 +50,7 @@ StackLocator::StackLocator() {
 
     invariant(pthread_attr_getstack(&attr, &_end, &size) == 0);
 
-    // TODO: Assumes stack grows downward on FreeBSD
+    // TODO: Assumes stack grows downward on NetBSD
     _begin = static_cast<char*>(_end) + size;
 }
 
