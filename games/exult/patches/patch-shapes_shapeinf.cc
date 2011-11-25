$NetBSD: patch-shapes_shapeinf.cc,v 1.1 2011/11/25 21:53:26 joerg Exp $

--- shapes/shapeinf.cc.orig	2011-11-25 17:35:12.000000000 +0000
+++ shapes/shapeinf.cc
@@ -32,6 +32,7 @@ Foundation, Inc., 59 Temple Place - Suit
 
 #include "utils.h"
 #include <iomanip>	/* Debugging */
+#include <cstring>
 using std::cout;
 using std::endl;
 
