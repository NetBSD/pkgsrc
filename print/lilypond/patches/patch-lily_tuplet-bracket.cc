$NetBSD: patch-lily_tuplet-bracket.cc,v 1.1 2013/06/16 20:46:52 joerg Exp $

--- lily/tuplet-bracket.cc.orig	2013-06-16 19:17:24.000000000 +0000
+++ lily/tuplet-bracket.cc
@@ -40,6 +40,7 @@
   todo: handle breaking elegantly.
 */
 
+#include "config.hh"
 #include "tuplet-bracket.hh"
 #include "axis-group-interface.hh"
 #include "line-interface.hh"
