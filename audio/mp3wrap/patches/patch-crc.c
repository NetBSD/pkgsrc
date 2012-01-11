$NetBSD: patch-crc.c,v 1.1 2012/01/11 19:42:36 hans Exp $

--- crc.c.orig	2003-01-10 23:19:35.000000000 +0100
+++ crc.c	2012-01-02 11:51:34.876664374 +0100
@@ -25,10 +25,11 @@
 
 #include <stdio.h>
 #include <stdlib.h>
+#include <stdint.h>
 
 #include "crc.h"
 
-static const u_int32_t crctab[256] = {
+static const uint32_t crctab[256] = {
 	0x00000000, 0x77073096, 0xee0e612c, 0x990951ba,
 	0x076dc419, 0x706af48f, 0xe963a535, 0x9e6495a3,
 	0x0edb8832, 0x79dcb8a4, 0xe0d5e91e, 0x97d2d988,
