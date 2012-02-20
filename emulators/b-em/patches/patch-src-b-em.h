$NetBSD: patch-src-b-em.h,v 1.1 2012/02/20 15:45:19 reinoud Exp $

--- src/b-em.h.orig	2010-10-25 13:51:30.000000000 +0000
+++ src/b-em.h
@@ -1,7 +1,10 @@
 /*B-em v2.1 by Tom Walker
   Main header file*/
 
+#include <stdio.h>
 #include <stdint.h>
+#include <stdlib.h>
+#include <string.h>
 //#define printf rpclog
 
 extern uint8_t *ram,*rom,*os;
