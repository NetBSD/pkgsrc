$NetBSD: patch-src_gen.cpp,v 1.4 2025/02/09 08:45:39 triaxx Exp $

Add missing header files.

--- src/gen.cpp.orig	2025-02-09 07:32:23.472515921 +0000
+++ src/gen.cpp
@@ -21,6 +21,7 @@ Permission is granted to anyone to use t
 #include<cstdio>
 #include<iostream>
 #include<fstream>
+#include<ctime>
 #include <unistd.h>
 
 const float F_RAND_MAX = (float)(RAND_MAX);
