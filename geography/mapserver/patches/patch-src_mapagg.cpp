$NetBSD: patch-src_mapagg.cpp,v 1.1 2024/08/22 16:16:30 gdt Exp $

Cope with API breakage in FreeType 2.13.3.

https://github.com/MapServer/MapServer/issues/7142

--- src/mapagg.cpp.orig	2024-08-22 15:16:49.699944231 +0000
+++ src/mapagg.cpp
@@ -291,10 +291,10 @@ bool decompose_ft_outline(const FT_Outli
 
   FT_Vector *point;
   FT_Vector *limit;
-  char *tags;
+  unsigned char *tags;
 
   int n;     // index of contour in outline
-  int first; // index of first point in contour
+  unsigned first; // index of first point in contour
   char tag;  // current point's state
 
   first = 0;
