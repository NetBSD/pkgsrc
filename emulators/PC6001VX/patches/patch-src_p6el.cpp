$NetBSD: patch-src_p6el.cpp,v 1.1 2019/12/21 23:39:48 joerg Exp $

--- src/p6el.cpp.orig	2019-12-21 17:32:31.750638038 +0000
+++ src/p6el.cpp
@@ -1,5 +1,6 @@
 #include <new>
 #include <cstdio>
+#include <cstdlib>
 #include <string>
 
 #include "pc6001v.h"
