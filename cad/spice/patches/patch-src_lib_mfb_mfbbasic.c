$NetBSD: patch-src_lib_mfb_mfbbasic.c,v 1.1 2013/03/02 17:51:49 joerg Exp $

--- src/lib/mfb/mfbbasic.c.orig	2013-03-01 22:43:30.000000000 +0000
+++ src/lib/mfb/mfbbasic.c
@@ -27,6 +27,8 @@ Author: -C- 1982 Giles C. Billingsley
 #define RadToDeg    57.29577951
 #define MFBFORMAT   MFBCurrent->strings
 
+void MFBGenCode(char *PM);
+
 /* Here we take care of externs */
 MFB *MFBCurrent;
 
