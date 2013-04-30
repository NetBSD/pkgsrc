$NetBSD: patch-src_util.h,v 1.1 2013/04/30 22:34:29 joerg Exp $

--- src/util.h.orig	2013-04-30 20:55:09.000000000 +0000
+++ src/util.h
@@ -16,6 +16,7 @@
 #include "gloox.h"
 
 #include <cmath>
+#include <cstdlib>
 #include <algorithm>
 #include <string>
 #include <list>
