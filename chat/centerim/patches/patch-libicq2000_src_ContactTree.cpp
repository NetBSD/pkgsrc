$NetBSD: patch-libicq2000_src_ContactTree.cpp,v 1.1 2013/05/06 15:04:55 joerg Exp $

--- libicq2000/src/ContactTree.cpp.orig	2013-05-04 14:35:03.000000000 +0000
+++ libicq2000/src/ContactTree.cpp
@@ -21,6 +21,7 @@
 
 #include "ContactTree.h"
 #include "events.h"
+#include <cstdlib>
 
 namespace ICQ2000 {
 
