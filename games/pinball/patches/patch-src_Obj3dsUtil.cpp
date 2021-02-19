$NetBSD: patch-src_Obj3dsUtil.cpp,v 1.1 2021/02/19 14:54:56 nia Exp $

Don't cast FILE * to int.

--- src/Obj3dsUtil.cpp.orig	2020-12-18 16:34:55.000000000 +0000
+++ src/Obj3dsUtil.cpp
@@ -570,7 +570,7 @@ extern "C" {
     unsigned int i=0; FILE* f=0;
 
     f=fopen( filename, "wt");
-    if ( ! f ) return (int) f;
+    if ( ! f ) return 0;
     for(i=0; i < in->no; i++) {
       t = fprintObject( f, & (in->vo[i]) );
     }
@@ -585,7 +585,7 @@ extern "C" {
     FILE* f=0;
     //debugf("+saveObject %s\n",filename);
     f=fopen( filename, "wt");
-    if ( ! f ) return (int) f;
+    if ( ! f ) return 0;
     t = fprintObject( f, o);
     fclose(f);
     //debug("-saveObject");
