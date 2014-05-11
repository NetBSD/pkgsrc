$NetBSD: patch-integr.c,v 1.2 2014/05/11 20:56:16 rodent Exp $

--- integr.c.orig	2005-06-21 18:27:18.000000000 +0000
+++ integr.c
@@ -5,7 +5,7 @@
  *
  */
 
-static const char intergrity_identifier[] = {
+const char intergrity_identifier[] = {
 	0xB0, 0x03, 0xB0, 0x02, 0xB0, 0x03,
 	0xB0, 0x04, 0xB0, 0x05,
 	0x90, 0x90, 0x90, 0x90,
