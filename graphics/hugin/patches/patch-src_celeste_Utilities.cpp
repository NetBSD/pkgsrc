$NetBSD: patch-src_celeste_Utilities.cpp,v 1.1 2013/06/27 15:51:49 joerg Exp $

--- src/celeste/Utilities.cpp.orig	2013-06-25 21:55:54.000000000 +0000
+++ src/celeste/Utilities.cpp
@@ -27,6 +27,7 @@ Copyright (c) 2002-3 Adriaan Tijsseling
 
 #include <math.h>
 #include <stdlib.h>
+#include <unistd.h>
 #include "Utilities.h"
 
 using namespace std; 
