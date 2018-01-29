$NetBSD: patch-trainer.cpp,v 1.1 2018/01/29 17:41:05 jperkin Exp $

Backport upstream fix for C++11.

--- trainer.cpp.orig	2010-05-09 05:34:08.000000000 +0000
+++ trainer.cpp
@@ -103,7 +103,7 @@ class TrainerImpl: public Trainer {
     if (!fn) {
       return false;
     }
-    x_.push_back(std::make_pair<std::string, FeatureNode *>(y, fn));
+    x_.push_back(std::make_pair(y, fn));
     return true;
   }
 
