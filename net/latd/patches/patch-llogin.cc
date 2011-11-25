$NetBSD: patch-llogin.cc,v 1.1 2011/11/25 22:14:17 joerg Exp $

--- llogin.cc.orig	2011-11-25 19:18:49.000000000 +0000
+++ llogin.cc
@@ -46,10 +46,13 @@
 #include <queue>
 #include <map>
 #include <string>
-#include <algo.h>
+#include <algorithm>
 #include <iterator>
 #include <string>
 #include <strstream>
+#include <iostream>
+
+using namespace std;
 
 #include "lat.h"
 #include "latcp.h"
