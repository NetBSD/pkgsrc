$NetBSD: patch-src_stats.cpp,v 1.1.1.1 2012/01/08 15:52:12 wiz Exp $

Add missing header.

--- src/stats.cpp.orig	2005-08-24 05:55:35.000000000 +0000
+++ src/stats.cpp
@@ -18,6 +18,7 @@
 #include "spell.h"
 #include "tile.h"
 #include "weapon.h"
+#include <string.h>
 
 extern bool verbose;
 
