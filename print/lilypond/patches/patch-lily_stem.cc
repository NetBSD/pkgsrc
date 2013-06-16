$NetBSD: patch-lily_stem.cc,v 1.1 2013/06/16 20:46:52 joerg Exp $

--- lily/stem.cc.orig	2013-06-16 19:03:50.000000000 +0000
+++ lily/stem.cc
@@ -37,6 +37,7 @@
   internal_height and internal_pure_height for all subsequent iterations.
 */
 
+#include "config.hh"
 #include "stem.hh"
 #include "spanner.hh"
 
