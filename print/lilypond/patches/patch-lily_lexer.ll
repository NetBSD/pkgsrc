$NetBSD: patch-lily_lexer.ll,v 1.1 2013/06/16 20:46:52 joerg Exp $

--- lily/lexer.ll.orig	2013-06-16 19:42:27.000000000 +0000
+++ lily/lexer.ll
@@ -41,6 +41,7 @@
 
 
 
+#include "config.hh"
 #include <cstdio>
 #include <cctype>
 #include <cerrno>
