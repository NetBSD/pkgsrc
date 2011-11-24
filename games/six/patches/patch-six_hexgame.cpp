$NetBSD: patch-six_hexgame.cpp,v 1.1 2011/11/24 14:07:12 joerg Exp $

--- six/hexgame.cpp.orig	2011-11-24 03:16:35.000000000 +0000
+++ six/hexgame.cpp
@@ -3,6 +3,7 @@
 #include <cassert>
 #include <cctype>
 #include <cstdio>
+#include <cstdlib>
 
 #include <string>
 
