$NetBSD: patch-src_scene-buffer.cpp,v 1.1 2015/03/08 23:25:39 joerg Exp $

--- src/scene-buffer.cpp.orig	2015-03-05 10:57:51.000000000 +0000
+++ src/scene-buffer.cpp
@@ -183,7 +183,6 @@ private:
     double wave_k_;
     double wave_period_;
     double wave_full_period_;
-    double wave_fill_;
     double wave_velocity_;
 
     std::vector<double> displacement_;
