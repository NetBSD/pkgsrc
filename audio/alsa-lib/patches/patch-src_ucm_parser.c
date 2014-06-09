$NetBSD: patch-src_ucm_parser.c,v 1.1 2014/06/09 12:21:07 ryoon Exp $

* NetBSD has no versionsort

--- src/ucm/parser.c.orig	2013-07-08 12:31:36.000000000 +0000
+++ src/ucm/parser.c
@@ -1254,7 +1254,7 @@ int uc_mgr_scan_master_configs(const cha
 		"%s", env ? env : ALSA_USE_CASE_DIR);
 	filename[MAX_FILE-1] = '\0';
 
-#ifdef _GNU_SOURCE
+#if defined(_GNU_SOURCE) && !defined(__NetBSD__)
 #define SORTFUNC	versionsort
 #else
 #define SORTFUNC	alphasort
