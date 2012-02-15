$NetBSD: patch-util.cc,v 1.1 2012/02/15 21:20:24 hans Exp $

--- util.cc.orig	2006-03-05 14:39:37.000000000 +0100
+++ util.cc	2012-01-17 00:39:15.102002150 +0100
@@ -27,6 +27,7 @@
 #include <string>
 #include <vector>
 
+#include <limits.h>
 #include <sys/param.h>
 #include <cstdlib>
 
