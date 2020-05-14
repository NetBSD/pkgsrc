$NetBSD: patch-src_taskmanager.cpp,v 1.1 2020/05/14 19:20:17 joerg Exp $

--- src/taskmanager.cpp.orig	2020-05-13 22:17:09.187513832 +0000
+++ src/taskmanager.cpp
@@ -908,10 +908,10 @@ bool Task::idMatch(const QString& id1, c
     if (id1.isEmpty() || id2.isEmpty())
         return false;
 
-    if (id1.contains(id2) > 0)
+    if (id1.contains(id2))
         return true;
 
-    if (id2.contains(id1) > 0)
+    if (id2.contains(id1))
         return true;
 
     return false;
