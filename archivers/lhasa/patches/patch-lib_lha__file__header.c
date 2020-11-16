$NetBSD: patch-lib_lha__file__header.c,v 1.1 2020/11/16 15:48:44 tsutsui Exp $

- avoid SIGSEGV on NetBSD/amd64 on decoding 8bit char filenames.
 https://github.com/fragglet/lhasa/pull/33

--- lib/lha_file_header.c.orig	2016-03-30 02:28:14.000000000 +0000
+++ lib/lha_file_header.c
@@ -194,7 +194,7 @@ static void fix_msdos_allcaps(LHAFileHea
 
 	if (header->path != NULL) {
 		for (i = 0; header->path[i] != '\0'; ++i) {
-			if (islower((unsigned) header->path[i])) {
+			if (islower((int)(unsigned char) header->path[i])) {
 				is_allcaps = 0;
 				break;
 			}
@@ -203,7 +203,7 @@ static void fix_msdos_allcaps(LHAFileHea
 
 	if (is_allcaps && header->filename != NULL) {
 		for (i = 0; header->filename[i] != '\0'; ++i) {
-			if (islower((unsigned) header->filename[i])) {
+			if (islower((int)(unsigned char) header->filename[i])) {
 				is_allcaps = 0;
 				break;
 			}
@@ -216,13 +216,13 @@ static void fix_msdos_allcaps(LHAFileHea
 		if (header->path != NULL) {
 			for (i = 0; header->path[i] != '\0'; ++i) {
 				header->path[i]
-				    = tolower((unsigned) header->path[i]);
+				    = tolower((int)(unsigned char) header->path[i]);
 			}
 		}
 		if (header->filename != NULL) {
 			for (i = 0; header->filename[i] != '\0'; ++i) {
 				header->filename[i]
-				    = tolower((unsigned) header->filename[i]);
+				    = tolower((int)(unsigned char) header->filename[i]);
 			}
 		}
 	}
