$NetBSD: patch-src_node__crypto.cc,v 1.1 2018/05/12 09:04:24 fhajny Exp $

<cmath> is needed for std::isnan() and std:isinf().

Based on nodejs/node pull request #19196:

 <https://github.com/nodejs/node/pull/19196>

--- src/node_crypto.cc.orig	2018-03-29 23:17:17.000000000 +0000
+++ src/node_crypto.cc
@@ -36,9 +36,9 @@
 #include "v8.h"
 
 #include <algorithm>
+#include <cmath>
 #include <errno.h>
 #include <limits.h>  // INT_MAX
-#include <math.h>
 #include <stdlib.h>
 #include <string.h>
 #include <vector>
