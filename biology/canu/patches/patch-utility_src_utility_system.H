$NetBSD: patch-utility_src_utility_system.H,v 1.3 2023/05/20 14:42:11 bacon Exp $

# Portability

--- utility/src/utility/system.H.orig	2021-12-17 20:57:47 UTC
+++ utility/src/utility/system.H
@@ -23,7 +23,7 @@
 #include "types.H"
 
 #include <signal.h>
-
+#include <cmath>
 
 
 double   getTime(void);
