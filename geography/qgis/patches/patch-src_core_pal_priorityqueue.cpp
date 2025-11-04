$NetBSD: patch-src_core_pal_priorityqueue.cpp,v 1.1 2025/11/04 00:54:47 gdt Exp $

Add missing include.  (Builds with PCH appear to mask the problem.)

https://github.com/qgis/QGIS/pull/63794

--- src/core/pal/priorityqueue.cpp.orig	2025-11-03 18:44:19.775172737 +0000
+++ src/core/pal/priorityqueue.cpp
@@ -28,6 +28,7 @@
  */
 
 #include <cstdio>
+#include <memory>
 
 #include "internalexception.h"
 #include "priorityqueue.h"
