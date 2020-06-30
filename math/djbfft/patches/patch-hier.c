$NetBSD: patch-hier.c,v 1.1 2020/06/30 17:24:56 schmonz Exp $

Adjust install paths.

--- hier.c.orig	1999-09-30 20:25:58.000000000 +0000
+++ hier.c
@@ -2,19 +2,16 @@
 
 void hier()
 {
-  h(auto_home,-1,-1,02755);
+  c(auto_home,"lib","libdjbfft.a",-1,-1,0644);
 
-  d(auto_home,"lib",-1,-1,02755);
-  c(auto_home,"lib","djbfft.a",-1,-1,0644);
-
-  d(auto_home,"include",-1,-1,02755);
-  c(auto_home,"include","real4.h",-1,-1,0644);
-  c(auto_home,"include","real8.h",-1,-1,0644);
-  c(auto_home,"include","complex4.h",-1,-1,0644);
-  c(auto_home,"include","complex8.h",-1,-1,0644);
-  c(auto_home,"include","fftc4.h",-1,-1,0644);
-  c(auto_home,"include","fftc8.h",-1,-1,0644);
-  c(auto_home,"include","fftr4.h",-1,-1,0644);
-  c(auto_home,"include","fftr8.h",-1,-1,0644);
-  c(auto_home,"include","fftfreq.h",-1,-1,0644);
+  d(auto_home,"include/djbfft",-1,-1,0755);
+  c(auto_home,"include/djbfft","real4.h",-1,-1,0644);
+  c(auto_home,"include/djbfft","real8.h",-1,-1,0644);
+  c(auto_home,"include/djbfft","complex4.h",-1,-1,0644);
+  c(auto_home,"include/djbfft","complex8.h",-1,-1,0644);
+  c(auto_home,"include/djbfft","fftc4.h",-1,-1,0644);
+  c(auto_home,"include/djbfft","fftc8.h",-1,-1,0644);
+  c(auto_home,"include/djbfft","fftr4.h",-1,-1,0644);
+  c(auto_home,"include/djbfft","fftr8.h",-1,-1,0644);
+  c(auto_home,"include/djbfft","fftfreq.h",-1,-1,0644);
 }
