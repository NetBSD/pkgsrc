$NetBSD: patch-src_mongo_platform_stack__locator__netbsd.cpp,v 1.1 2023/07/29 11:51:15 adam Exp $

Add NetBSD support.

--- src/mongo/platform/stack_locator_netbsd.cpp.orig	2023-07-27 07:57:01.000000000 +0000
+++ src/mongo/platform/stack_locator_netbsd.cpp
@@ -32,7 +32,6 @@
 #include "mongo/platform/stack_locator.h"
 
 #include <pthread.h>
-#include <pthread_np.h>
 
 #include "mongo/util/assert_util.h"
 #include "mongo/util/scopeguard.h"
@@ -52,7 +51,7 @@ StackLocator::StackLocator() {
 
     invariant(pthread_attr_getstack(&attr, &_end, &size) == 0);
 
-    // TODO: Assumes stack grows downward on FreeBSD
+    // TODO: Assumes stack grows downward on NetBSD
     _begin = static_cast<char*>(_end) + size;
 }
 
