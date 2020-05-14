$NetBSD: patch-rlog_StdioNode.cpp,v 1.1 2020/05/14 19:08:07 joerg Exp $

pthread_self() often returns a pointer, so use widest type.

--- rlog/StdioNode.cpp.orig	2020-05-12 13:29:29.773360583 +0000
+++ rlog/StdioNode.cpp
@@ -220,7 +220,7 @@ StdioNode::publish( const RLogData &data
 #ifndef _WIN32
     if (outputThreadId) {
         char tid[16] = "";
-        snprintf(tid,15,"%lu",pthread_self());
+        snprintf(tid,15,"%ju",(uintmax_t)pthread_self());
         ss << "[tid:" << tid << "] ";
     }
 #endif
