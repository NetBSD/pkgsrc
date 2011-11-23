$NetBSD: patch-option.cpp,v 1.1 2011/11/23 23:28:06 joerg Exp $

--- option.cpp.orig	2011-11-23 16:46:06.000000000 +0000
+++ option.cpp
@@ -1,3 +1,4 @@
+#include <string.h>
 #include "option.h"
 
 Option::Option()
