$NetBSD: patch-src_frontends_controllers_helper__funcs.h,v 1.1 2011/11/25 22:16:26 joerg Exp $

--- src/frontends/controllers/helper_funcs.h.orig	2011-11-25 17:08:24.000000000 +0000
+++ src/frontends/controllers/helper_funcs.h
@@ -15,6 +15,7 @@
 #ifndef HELPERFUNCS_H
 #define HELPERFUNCS_H
 
+#include <algorithm>
 #include <utility> // pair
 
 #ifdef __GNUG__
