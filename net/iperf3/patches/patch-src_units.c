$NetBSD: patch-src_units.c,v 1.1 2015/02/02 12:25:20 he Exp $

Avoid warning for using toupper() with signed chars.

--- src/units.c.orig	2015-01-09 17:44:11.000000000 +0000
+++ src/units.c
@@ -259,7 +259,7 @@ extern    "C"
 	{
 	    inNum *= 8;
 	}
-	switch    (toupper(inFormat))
+	switch    (toupper((u_char)inFormat))
 	{
 	case 'B':
 	    conv = UNIT_CONV;
