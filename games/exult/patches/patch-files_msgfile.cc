$NetBSD: patch-files_msgfile.cc,v 1.1 2011/11/25 21:53:26 joerg Exp $

--- files/msgfile.cc.orig	2011-11-25 17:32:19.000000000 +0000
+++ files/msgfile.cc
@@ -24,6 +24,7 @@
 
 #include <iostream>
 #include <vector>
+#include <cstdlib>
 #include "utils.h"
 
 using std::istream;
