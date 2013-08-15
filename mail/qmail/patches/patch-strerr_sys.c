$NetBSD: patch-strerr_sys.c,v 1.1 2013/08/15 15:43:48 schmonz Exp $

Compile on Darwin.

--- strerr_sys.c.orig	1998-06-15 10:53:16.000000000 +0000
+++ strerr_sys.c
@@ -1,7 +1,7 @@
 #include "error.h"
 #include "strerr.h"
 
-struct strerr strerr_sys;
+struct strerr strerr_sys = {0,0,0,0};
 
 void strerr_sysinit()
 {
