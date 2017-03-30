$NetBSD: patch-dbf.h,v 1.1 2017/03/30 15:54:03 adam Exp $

Get rid of non-standard stdint-gcc.h.

--- dbf.h.orig	2017-03-30 15:48:41.000000000 +0000
+++ dbf.h
@@ -3,7 +3,7 @@
 
 #include <stdio.h>
 // 2017-01-18 paulf: include file to define precise integer/long types
-#include <stdint-gcc.h>
+#include <stdint.h>
 #include "bool.h"
 
 #ifndef uchar
