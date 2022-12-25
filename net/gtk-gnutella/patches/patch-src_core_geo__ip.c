$NetBSD: patch-src_core_geo__ip.c,v 1.2 2022/12/25 18:08:51 wiz Exp $

Fix build on NetBSD with SSP.
https://github.com/gtk-gnutella/gtk-gnutella/pull/35

--- src/core/geo_ip.c.orig	2022-02-25 16:06:19.000000000 +0000
+++ src/core/geo_ip.c
@@ -435,7 +435,7 @@ gip_load(FILE *f, unsigned idx, const ch
 		gip_source[idx].mtime = buf.st_mtime;
 	}
 
-	while (fgets(ARYLEN(line), f)) {
+	while (fgets(line, sizeof(line), f)) {
 		linenum++;
 
 		/*
