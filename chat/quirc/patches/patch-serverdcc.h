$NetBSD: patch-serverdcc.h,v 1.1 2011/11/27 23:49:38 marino Exp $

--- serverdcc.h.orig	2011-11-27 23:22:01.686524000 +0000
+++ serverdcc.h
@@ -9,6 +9,7 @@
 #include "config.h"
 
 #include <string>
+#include <string.h>
 #ifdef USING_STD_STRING
 using std::string;
 #endif
