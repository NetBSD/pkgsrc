$NetBSD: patch-include_interlocks.h,v 1.1 2016/03/29 22:06:48 joerg Exp $

--- include/interlocks.h.orig	2016-03-28 17:49:58.186898677 +0000
+++ include/interlocks.h
@@ -37,7 +37,7 @@
 //Channels
 #define CR (0x0020)
 #define CW (0x0040)
-#define CB (0x0060)
+#define CSOUND_CB (0x0060)
 
 //Stack
 #define SK (0x0080)
