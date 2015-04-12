$NetBSD: patch-integr.c,v 1.3 2015/04/12 15:45:00 tnn Exp $

Make guard variable used by the integrity check non-static, so
that it won't get dropped as unused.

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
