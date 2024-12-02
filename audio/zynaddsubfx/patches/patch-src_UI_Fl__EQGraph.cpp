$NetBSD: patch-src_UI_Fl__EQGraph.cpp,v 1.1 2024/12/02 07:46:04 nia Exp $

Fix "error: call of overloaded 'log(int)' is ambiguous" on SunOS.

--- src/UI/Fl_EQGraph.cpp.orig	2024-12-02 07:44:57.508262122 +0000
+++ src/UI/Fl_EQGraph.cpp
@@ -174,7 +174,7 @@ double Fl_EQGraph::getresponse(int maxy,
         mag *= abs(num_res/dem_res);
     }
 
-    float dbresp=20*log(mag*gain)/log(10);
+    float dbresp=20*log(mag*gain)/log(10.0);
 
     //rescale
     return (int) ((dbresp/MAX_DB+1.0)*maxy/2.0);
