$NetBSD: patch-src_memory_Ram.cc,v 1.1 2011/11/24 14:12:21 joerg Exp $

--- src/memory/Ram.cc.orig	2011-11-24 02:45:09.000000000 +0000
+++ src/memory/Ram.cc
@@ -2,6 +2,7 @@
 
 #include "Ram.hh"
 #include "SimpleDebuggable.hh"
+#include <cstring>
 
 namespace openmsx {
 
