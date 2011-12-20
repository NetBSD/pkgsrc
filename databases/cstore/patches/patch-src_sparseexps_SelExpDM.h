$NetBSD: patch-src_sparseexps_SelExpDM.h,v 1.1 2011/12/20 13:42:48 wiz Exp $

Add missing header.

--- src/sparseexps/SelExpDM.h.orig	2006-10-17 19:36:12.000000000 +0000
+++ src/sparseexps/SelExpDM.h
@@ -67,7 +67,7 @@
 #include "../AM/PagePlacer.h"
 #include <ctime>
 #include "../UnitTests/UnitTest.h"
-#include <fstream.h>
+#include <fstream>
 
 class SelExpDM : public UnitTest
 {
