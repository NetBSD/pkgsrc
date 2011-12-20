$NetBSD: patch-src_TM_WosTupleIter.cpp,v 1.1 2011/12/20 13:42:47 wiz Exp $

Add missing header.

--- src/TM/WosTupleIter.cpp.orig	2005-07-06 04:06:24.000000000 +0000
+++ src/TM/WosTupleIter.cpp
@@ -35,6 +35,7 @@
  */
 
 #include <string>
+#include <stdlib.h>
 #include <vector>
 
 #include "WosTuple.h"  //tuple representation of WOS projection
