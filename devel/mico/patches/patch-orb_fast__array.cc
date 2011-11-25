$NetBSD: patch-orb_fast__array.cc,v 1.1 2011/11/25 21:46:29 joerg Exp $

--- orb/fast_array.cc.orig	2011-11-25 19:49:40.000000000 +0000
+++ orb/fast_array.cc
@@ -40,6 +40,7 @@
 
 #endif // FAST_PCH
 
+#include <climits>
 
 using namespace std;
 
