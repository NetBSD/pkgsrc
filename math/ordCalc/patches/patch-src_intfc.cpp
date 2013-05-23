$NetBSD: patch-src_intfc.cpp,v 1.1 2013/05/23 18:41:21 joerg Exp $

--- src/intfc.cpp.orig	2013-05-23 17:22:49.000000000 +0000
+++ src/intfc.cpp
@@ -4,6 +4,7 @@
 #include <map>
 #include <assert.h>
 #include <ctype.h>
+#include <unistd.h>
 #include "ordTop.h"
 
 
