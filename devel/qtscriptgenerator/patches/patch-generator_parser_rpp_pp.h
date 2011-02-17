$NetBSD: patch-generator_parser_rpp_pp.h,v 1.1 2011/02/17 09:51:01 markd Exp $

Fix build with gcc4.3

--- generator/parser/rpp/pp.h.orig	2009-02-20 11:42:24.000000000 +0000
+++ generator/parser/rpp/pp.h
@@ -28,6 +28,7 @@
 #include <iostream>
 #include <cassert>
 #include <cctype>
+#include <cstdio>
 
 #include <fcntl.h>
 
