$NetBSD: patch-utility_src_utility_types.H,v 1.2 2023/05/20 11:27:27 bacon Exp $

# Portability

--- utility/src/utility/types.H.orig	2021-12-17 20:58:13 UTC
+++ utility/src/utility/types.H
@@ -55,7 +55,7 @@
 #include <ctype.h>
 
 #include <float.h>
-#include <math.h>
+#include <cmath>
 
 #include <assert.h>
 #include <errno.h>
