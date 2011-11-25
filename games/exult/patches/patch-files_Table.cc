$NetBSD: patch-files_Table.cc,v 1.1 2011/11/25 21:53:26 joerg Exp $

--- files/Table.cc.orig	2011-11-25 17:26:41.000000000 +0000
+++ files/Table.cc
@@ -27,6 +27,7 @@ Foundation, Inc., 59 Temple Place - Suit
 #endif
 #include <iostream>
 #include "exceptions.h"
+#include <cstdlib>
 #include "utils.h"
 
 using std::string;
