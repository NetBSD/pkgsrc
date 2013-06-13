$NetBSD: patch-src_gen.cpp,v 1.3 2013/06/13 21:42:22 joerg Exp $

--- src/gen.cpp.orig	2013-06-13 19:51:44.000000000 +0000
+++ src/gen.cpp
@@ -21,6 +21,8 @@ Permission is granted to anyone to use t
 #include<cstdio>
 #include<iostream>
 #include<fstream>
+#include<ctime>
+#include <unistd.h>
 
 const float F_RAND_MAX = (float)(RAND_MAX);
 
