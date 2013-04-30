$NetBSD: patch-poxml_antlr_src_BitSet.cpp,v 1.1 2013/04/30 22:34:30 joerg Exp $

--- poxml/antlr/src/BitSet.cpp.orig	2013-04-29 23:21:52.000000000 +0000
+++ poxml/antlr/src/BitSet.cpp
@@ -1,4 +1,5 @@
 #include "antlr/BitSet.hpp"
+#include <string>
 
 ANTLR_BEGIN_NAMESPACE(antlr)
 
