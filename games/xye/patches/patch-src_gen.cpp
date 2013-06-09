$NetBSD: patch-src_gen.cpp,v 1.2 2013/06/09 06:30:14 ryoon Exp $

--- src/gen.cpp.orig	2013-06-09 06:21:13.000000000 +0000
+++ src/gen.cpp
@@ -21,6 +21,7 @@ Permission is granted to anyone to use t
 #include<cstdio>
 #include<iostream>
 #include<fstream>
+#include<ctime>
 
 const float F_RAND_MAX = (float)(RAND_MAX);
 
