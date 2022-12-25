$NetBSD: patch-src_core_bogons.c,v 1.2 2022/12/25 18:08:51 wiz Exp $

Fix build on NetBSD with SSP.
https://github.com/gtk-gnutella/gtk-gnutella/pull/35

--- src/core/bogons.c.orig	2022-02-25 16:06:19.000000000 +0000
+++ src/core/bogons.c
@@ -81,7 +81,7 @@ bogons_load(FILE *f)
 		bogons_mtime = buf.st_mtime;
 	}
 
-	while (fgets(ARYLEN(line), f)) {
+	while (fgets(line, sizeof(line), f)) {
 		linenum++;
 
 		/*
