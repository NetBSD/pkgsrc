$NetBSD: patch-src_FlexLexer.h,v 1.1 2016/11/11 08:14:54 wiz Exp $

Add workaround for building lilypond-2.18.2.
See https://github.com/westes/flex/issues/124

--- src/FlexLexer.h.orig	2016-10-21 00:43:44.000000000 +0000
+++ src/FlexLexer.h
@@ -49,6 +49,9 @@
 #define __FLEX_LEXER_H
 
 #include <iostream>
+#  ifndef FLEX_STD
+#    define FLEX_STD std::
+#  endif
 
 extern "C++" {
 
