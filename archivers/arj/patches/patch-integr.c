$NetBSD: patch-integr.c,v 1.1 2013/11/04 16:41:43 joerg Exp $

--- integr.c.orig	2013-11-04 16:18:17.000000000 +0000
+++ integr.c
@@ -5,7 +5,7 @@
  *
  */
 
-static const char intergrity_identifier[] = {
+const char intergrity_identifier[] = {
 	0xB0, 0x03, 0xB0, 0x02, 0xB0, 0x03,
 	0xB0, 0x04, 0xB0, 0x05,
 	0x90, 0x90, 0x90, 0x90,
