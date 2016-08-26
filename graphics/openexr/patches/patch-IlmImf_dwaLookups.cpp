$NetBSD: patch-IlmImf_dwaLookups.cpp,v 1.1 2016/08/26 17:19:49 joerg Exp $

--- IlmImf/dwaLookups.cpp.orig	2016-06-06 22:42:15.936629432 +0000
+++ IlmImf/dwaLookups.cpp
@@ -436,6 +436,7 @@ generateToNonlinear()
 int
 cpuCount()
 {
+    return 1; // Semi-reliably crashes in bulk builds
     if (!IlmThread::supportsThreads()) return 1;
 
     int cpuCount = 1;
