$NetBSD: patch-src_core_hostiles.c,v 1.1 2022/12/25 17:55:14 wiz Exp $

Fix build on NetBSD with SSP.

--- src/core/hostiles.c.orig	2022-02-25 16:06:19.000000000 +0000
+++ src/core/hostiles.c
@@ -294,7 +294,7 @@ hostiles_load(FILE *f, hostiles_t which)
 
 	hostile_db[which] = iprange_new();
 
-	while (fgets(ARYLEN(line), f)) {
+	while (fgets(line, sizeof(line), f)) {
 		linenum++;
 
 		/*
