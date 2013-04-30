$NetBSD: patch-src_wxgui_ceria.cpp,v 1.1 2013/04/30 22:25:40 joerg Exp $

--- src/wxgui/ceria.cpp.orig	2013-04-30 20:14:19.000000000 +0000
+++ src/wxgui/ceria.cpp
@@ -7,6 +7,7 @@
 #define _USE_MATH_DEFINES
 #endif
 #include <stdio.h>
+#include <stdlib.h>
 #include <ctype.h>
 #include <math.h>
 #include <assert.h>
