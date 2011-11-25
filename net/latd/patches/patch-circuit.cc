$NetBSD: patch-circuit.cc,v 1.1 2011/11/25 22:14:17 joerg Exp $

--- circuit.cc.orig	2011-11-25 19:19:21.000000000 +0000
+++ circuit.cc
@@ -22,6 +22,7 @@
 #include <map>
 #include <queue>
 #include <iterator>
+#include <cstring>
 
 #include "lat.h"
 #include "latcp.h"
