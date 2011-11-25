$NetBSD: patch-src_bmp.cpp,v 1.1 2011/11/25 21:51:13 joerg Exp $

--- src/bmp.cpp.orig	2011-11-25 15:19:08.000000000 +0000
+++ src/bmp.cpp
@@ -4,14 +4,16 @@
 // Modified by Volker Blanz, 25.4.2001
 //
 
-#include <iostream.h>
-#include <fstream.h>
+#include <iostream>
+#include <fstream>
 #include <stdio.h>
 #include <string.h>
 #include "LA.h"
 #include "Namen.h"
 #include "bmp.h"
 
+using namespace std;
+
 // from ioutil:
 
 WORDX readWord(FILE *f) {
