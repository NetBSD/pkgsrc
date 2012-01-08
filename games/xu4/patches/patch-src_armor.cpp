$NetBSD: patch-src_armor.cpp,v 1.1.1.1 2012/01/08 15:52:12 wiz Exp $

Add missing header.

--- src/armor.cpp.orig	2004-05-26 03:32:52.000000000 +0000
+++ src/armor.cpp
@@ -12,6 +12,7 @@
 #include "error.h"
 #include "names.h"
 #include "tile.h"
+#include <string.h>
 
 using std::vector;
 using std::string;
