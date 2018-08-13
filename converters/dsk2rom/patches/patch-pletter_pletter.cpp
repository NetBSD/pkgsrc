$NetBSD: patch-pletter_pletter.cpp,v 1.1 2018/08/13 15:53:49 nia Exp $

Add missing includes.

--- pletter/pletter.cpp.orig	2007-05-27 11:18:42.000000000 +0000
+++ pletter/pletter.cpp
@@ -9,6 +9,9 @@
 
 */
 
+#include <cstdlib>
+#include <cstring>
+#include <cstdio>
 #include <string>
 using namespace std;
 
