$NetBSD: patch-src_fe-common_module-formats.c,v 1.1 2014/09/30 08:59:58 jperkin Exp $

Fix /beep output.

--- src/fe-common/module-formats.c.orig	2011-06-13 18:10:41.000000000 +0000
+++ src/fe-common/module-formats.c
@@ -30,7 +30,7 @@ FORMAT_REC fecommon_icb_formats[] = {
 	{ "status", "[$0] $1", 2, { 0, 0 } },
 	{ "important", "[$0!] $1", 2, { 0, 0 } },
 	{ "status", "{error [Error]} $0", 1, { 0 } },
-	{ "beep", "[Beep] $1 beeps you", 1, { 0 } },
+	{ "beep", "[Beep] $0 beeps you", 1, { 0 } },
 
 	{ NULL, NULL, 0 }
 };
