$NetBSD: patch-src_mn.cpp,v 1.1 2012/12/20 21:47:31 joerg Exp $

--- src/mn.cpp.orig	2012-12-20 18:38:51.000000000 +0000
+++ src/mn.cpp
@@ -218,7 +218,7 @@ void helpTex()
 
 }
 
-
+int
 main(int argc, char  ** argv)
 {
     
