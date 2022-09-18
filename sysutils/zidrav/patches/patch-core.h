$NetBSD: patch-core.h,v 1.2 2022/09/18 13:49:00 he Exp $

Include <string.h> and use an unsigned long for crc_table[]
for the benefit of LP32 platforms.

--- core.h.orig	2011-11-22 19:25:48.000000000 +0000
+++ core.h
@@ -22,6 +22,7 @@
 #include <iostream>
 #include <fstream>
 #include <string>
+#include <string.h>
 
 using namespace std;
 
@@ -48,7 +49,7 @@ public:
 #define QSV		KSigver( ZQ, QVER )
 
 
-const long crc_table[256] = {		// it's just easier this way, alright? It's one K of data, I'm allowed a global if I want one
+const unsigned long crc_table[256] = {		// it's just easier this way, alright? It's one K of data, I'm allowed a global if I want one
   0x00000000L, 0x77073096L, 0xee0e612cL, 0x990951baL, 0x076dc419L,
   0x706af48fL, 0xe963a535L, 0x9e6495a3L, 0x0edb8832L, 0x79dcb8a4L,
   0xe0d5e91eL, 0x97d2d988L, 0x09b64c2bL, 0x7eb17cbdL, 0xe7b82d07L,
