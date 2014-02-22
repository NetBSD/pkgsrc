$NetBSD: patch-src_FaacEncoder.cpp,v 1.1 2014/02/22 14:51:03 wiedi Exp $

string.h is needed for memmove()
--- src/FaacEncoder.cpp.orig	2013-07-15 05:50:42.000000000 +0000
+++ src/FaacEncoder.cpp
@@ -37,7 +37,7 @@
 #ifdef HAVE_FAAC_LIB
 
 
-
+#include <string.h>
 #include "Exception.h"
 #include "Util.h"
 #include "FaacEncoder.h"
