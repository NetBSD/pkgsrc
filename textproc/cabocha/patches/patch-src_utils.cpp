$NetBSD: patch-src_utils.cpp,v 1.1 2013/05/23 15:07:58 joerg Exp $

--- src/utils.cpp.orig	2013-05-23 10:52:37.000000000 +0000
+++ src/utils.cpp
@@ -4,4 +4,9 @@
 //
 //  Copyright(C) 2001-2008 Taku Kudo <taku@chasen.org>
+
+#ifdef HAVE_CONFIG_H
+#include "config.h"
+#endif
+
 #ifdef HAVE_UNISTD_H
 #include <unistd.h>
@@ -16,8 +21,4 @@
 #include "utils.h"
 
-#ifdef HAVE_CONFIG_H
-#include "config.h"
-#endif
-
 namespace CaboCha {
 
