$NetBSD: patch-igs_datetime.cc,v 1.1 2016/12/17 23:22:30 joerg Exp $

--- igs/datetime.cc.orig	2015-12-25 17:00:08.000000000 +0000
+++ igs/datetime.cc
@@ -19,7 +19,6 @@
  * 
  */
 
-#define _XOPEN_SOURCE 1
 #ifndef _GNU_SOURCE
 #define _GNU_SOURCE 1
 #endif
