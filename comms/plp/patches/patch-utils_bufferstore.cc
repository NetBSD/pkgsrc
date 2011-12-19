$NetBSD: patch-utils_bufferstore.cc,v 1.1 2011/12/19 13:44:07 wiz Exp $

Update for C++ changes.

--- utils/bufferstore.cc.orig	1999-04-12 21:17:03.000000000 +0000
+++ utils/bufferstore.cc
@@ -19,8 +19,8 @@
 //
 //  e-mail philip.proudman@btinternet.com
 
-#include <stream.h>
-#include <iomanip.h>
+#include <iomanip>
+using namespace std;
 #include <string.h>
 
 #include "bufferstore.h"
