$NetBSD: patch-lib_base_CStringUtil.cpp,v 1.1 2011/11/22 20:07:20 joerg Exp $

--- lib/base/CStringUtil.cpp.orig	2011-11-22 19:35:22.000000000 +0000
+++ lib/base/CStringUtil.cpp
@@ -20,6 +20,7 @@
 #include <cstdio>
 #include <cstdlib>
 #include <algorithm>
+#include <cstring>
 
 //
 // CStringUtil
