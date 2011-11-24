$NetBSD: patch-src_qjackctlPatchbayRack.cpp,v 1.1 2011/11/24 14:25:17 joerg Exp $

--- src/qjackctlPatchbayRack.cpp.orig	2011-11-24 03:02:27.000000000 +0000
+++ src/qjackctlPatchbayRack.cpp
@@ -22,6 +22,7 @@
 #include "qjackctlPatchbayRack.h"
 
 #include <QRegExp>
+#include <cstdlib>
 
 
 //----------------------------------------------------------------------
