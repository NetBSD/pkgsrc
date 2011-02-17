$NetBSD: patch-poxml_antlr_antlr_CharScanner.hpp,v 1.1 2011/02/17 08:31:51 markd Exp $

build with gcc4.3

--- poxml/antlr/antlr/CharScanner.hpp.orig	2005-09-10 08:21:05.000000000 +0000
+++ poxml/antlr/antlr/CharScanner.hpp
@@ -42,6 +42,7 @@
 #include "antlr/BitSet.hpp"
 #include "antlr/LexerSharedInputState.hpp"
 #include <map>
+#include <cstdio>
 
 ANTLR_BEGIN_NAMESPACE(antlr)
 
