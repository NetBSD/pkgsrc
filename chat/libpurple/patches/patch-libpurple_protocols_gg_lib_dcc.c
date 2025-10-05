$NetBSD: patch-libpurple_protocols_gg_lib_dcc.c,v 1.1 2025/10/05 16:01:15 wiz Exp $

Fix -Wchar-subscripts in ctype(3) functions

--- libpurple/protocols/gg/lib/dcc.c~	2024-09-17 10:52:23.000000000 +0200
+++ libpurple/protocols/gg/lib/dcc.c	2025-10-05 15:11:48.358953003 +0200
@@ -180,7 +180,7 @@
 		ext = name + strlen(name);
 
 	for (i = 0, p = name; i < 8 && p < ext; i++, p++)
-		d->file_info.short_filename[i] = toupper(name[i]);
+		d->file_info.short_filename[i] = toupper((unsigned char)name[i]);
 
 	if (i == 8 && p < ext) {
 		d->file_info.short_filename[6] = '~';
@@ -189,7 +189,7 @@
 
 	if (strlen(ext) > 0) {
 		for (j = 0; *ext && j < 4; j++, p++)
-			d->file_info.short_filename[i + j] = toupper(ext[j]);
+			d->file_info.short_filename[i + j] = toupper((unsigned char)ext[j]);
 	}
 
 	for (q = d->file_info.short_filename; *q; q++) {
