$NetBSD: patch-six_carrier.h,v 1.1 2011/11/24 14:07:12 joerg Exp $

--- six/carrier.h.orig	2011-11-24 03:21:28.000000000 +0000
+++ six/carrier.h
@@ -4,6 +4,7 @@
 
 #include <iostream>
 #include <vector>
+#include <cstring>
 
 using std::vector;
 using std::istream;
