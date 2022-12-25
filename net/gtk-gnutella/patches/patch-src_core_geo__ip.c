$NetBSD: patch-src_core_geo__ip.c,v 1.1 2022/12/25 17:55:14 wiz Exp $

Fix build on NetBSD with SSP.

--- src/core/geo_ip.c.orig	2022-02-25 16:06:19.000000000 +0000
+++ src/core/geo_ip.c
@@ -435,7 +435,7 @@ gip_load(FILE *f, unsigned idx, const ch
 		gip_source[idx].mtime = buf.st_mtime;
 	}
 
-	while (fgets(ARYLEN(line), f)) {
+	while (fgets(line, sizeof(line), f)) {
 		linenum++;
 
 		/*
