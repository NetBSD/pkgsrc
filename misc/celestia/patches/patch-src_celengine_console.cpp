$NetBSD: patch-src_celengine_console.cpp,v 1.2 2012/07/03 17:40:36 joerg Exp $

--- src/celengine/console.cpp.orig	2005-07-19 20:30:54.000000000 +0000
+++ src/celengine/console.cpp
@@ -9,6 +9,7 @@
 
 #include <cstdarg>
 #include <cstdio>
+#include <cstring>
 #include <cassert>
 #include "celutil/utf8.h"
 #include "gl.h"
