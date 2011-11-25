$NetBSD: patch-setup.cpp,v 1.1 2011/11/25 21:52:33 joerg Exp $

--- setup.cpp.orig	2011-11-25 17:25:49.000000000 +0000
+++ setup.cpp
@@ -7,8 +7,8 @@
 //  routines are run when EXchess first starts up.
 //
 
-#include <iostream.h>
-#include <fstream.h>
+#include <iostream>
+#include <fstream>
 #include <stdlib.h>
 #include <string.h>
 
@@ -18,6 +18,8 @@
 #include "funct.h"
 #include "hash.h"
 
+using namespace std;
+
 /* Simple tables for quick in_check? tests */
 int check_table[64][64];
 int rook_check_table[64][64];
