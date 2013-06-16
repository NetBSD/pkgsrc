$NetBSD: patch-lily_grob-property.cc,v 1.1 2013/06/16 20:46:52 joerg Exp $

--- lily/grob-property.cc.orig	2013-06-16 19:15:44.000000000 +0000
+++ lily/grob-property.cc
@@ -2,6 +2,7 @@
   Implement storage and manipulation of grob properties.
 */
 
+#include "config.hh"
 #include <cstring>
 
 #include "main.hh"
