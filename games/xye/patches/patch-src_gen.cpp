$NetBSD: patch-src_gen.cpp,v 1.1 2013/04/29 21:31:11 joerg Exp $

--- src/gen.cpp.orig	2013-04-29 18:55:25.000000000 +0000
+++ src/gen.cpp
@@ -19,6 +19,7 @@ Permission is granted to anyone to use t
 #include "gen.h"
 #include "vxsdl.h"
 #include<cstdio>
+#include<ctime>
 
 const float F_RAND_MAX = (float)(RAND_MAX);
 
