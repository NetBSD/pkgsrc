$NetBSD: patch-strerr__sys.c,v 1.1 2017/05/26 14:34:43 schmonz Exp $

Initialize strerr_sys to build on Mac OS X (modeled after the patch
for qmail).

--- strerr_sys.c.orig	Fri Sep  4 22:33:37 1998
+++ strerr_sys.c
@@ -1,7 +1,7 @@
 #include "error.h"
 #include "strerr.h"
 
-struct strerr strerr_sys;
+struct strerr strerr_sys = {0,0,0,0};
 
 void strerr_sysinit()
 {
