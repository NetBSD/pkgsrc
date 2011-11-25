$NetBSD: patch-libvideogfx_utility_math.cc,v 1.1 2011/11/25 21:59:26 joerg Exp $

--- libvideogfx/utility/math.cc.orig	2011-11-25 19:39:49.000000000 +0000
+++ libvideogfx/utility/math.cc
@@ -19,7 +19,7 @@
 
 #include "libvideogfx/utility/math.hh"
 #include <assert.h>
-#include <iostream.h>
+#include <iostream>
 using namespace std;
 
 namespace videogfx {
