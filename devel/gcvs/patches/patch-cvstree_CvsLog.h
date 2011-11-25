$NetBSD: patch-cvstree_CvsLog.h,v 1.1 2011/11/25 21:42:44 joerg Exp $

--- cvstree/CvsLog.h.orig	2011-11-25 17:57:38.000000000 +0000
+++ cvstree/CvsLog.h
@@ -28,6 +28,7 @@
 #include <vector>
 #include <time.h>
 #include <stdio.h>
+#include <cstring>
 
 #if defined(_MSC_VER) && _MSC_VER < 0x514 // VC7
 #	include <iostream.h>
