$NetBSD: patch-lily_context-def.cc,v 1.1 2013/06/16 20:46:52 joerg Exp $

--- lily/context-def.cc.orig	2013-06-16 19:28:17.000000000 +0000
+++ lily/context-def.cc
@@ -20,6 +20,7 @@
 /* TODO: should junk this class an replace by
    a single list of context modifications?  */
 
+#include "config.hh"
 #include "context-def.hh"
 
 #include "context.hh"
