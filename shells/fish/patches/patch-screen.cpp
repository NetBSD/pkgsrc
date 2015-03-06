$NetBSD: patch-screen.cpp,v 1.1 2015/03/06 21:03:20 ryoon Exp $

--- screen.cpp.orig	2015-02-16 19:07:12.000000000 +0000
+++ screen.cpp
@@ -112,10 +112,11 @@ static size_t try_sequence(const char *s
  */
 static size_t next_tab_stop(size_t in)
 {
+    int itabs = init_tabs;
     /*
       Assume tab stops every 8 characters if undefined
     */
-    size_t tab_width = (init_tabs > 0 ? (size_t)init_tabs : 8);
+    size_t tab_width = (itabs > 0 ? (size_t)itabs : 8);
     return ((in/tab_width)+1)*tab_width;
 }
 
