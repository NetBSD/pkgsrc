$NetBSD: patch-rlog_StdioNode.cpp,v 1.2 2023/07/19 15:19:36 nia Exp $

pthread_self() often returns a pointer, so use widest type.

--- rlog/StdioNode.cpp.orig	2005-09-20 20:17:36.000000000 +0000
+++ rlog/StdioNode.cpp
@@ -41,6 +41,7 @@
 #endif
 
 #include <stdio.h>
+#include <stdint.h>
 #include <stdarg.h>
 
 #ifdef _WIN32
@@ -220,7 +221,7 @@ StdioNode::publish( const RLogData &data
 #ifndef _WIN32
     if (outputThreadId) {
         char tid[16] = "";
-        snprintf(tid,15,"%lu",pthread_self());
+        snprintf(tid,15,"%ju",(uintmax_t)pthread_self());
         ss << "[tid:" << tid << "] ";
     }
 #endif
