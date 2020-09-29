$NetBSD: patch-libpcsxcore_misc.c,v 1.1 2020/09/29 12:23:03 nia Exp $

Portability.

--- libpcsxcore/misc.c.orig	2019-03-06 11:37:17.000000000 +0000
+++ libpcsxcore/misc.c
@@ -124,7 +124,7 @@ int GetCdromFile(u8 *mdir, u8 *time, s8 
 		i += dir->length[0];
 
 		if (dir->flags[0] & 0x2) { // it's a dir
-			if (!strnicmp((char *)&dir->name[0], filename, dir->name_len[0])) {
+			if (!strncasecmp((char *)&dir->name[0], filename, dir->name_len[0])) {
 				if (filename[dir->name_len[0]] != '\\') continue;
 
 				filename += dir->name_len[0] + 1;
@@ -135,7 +135,7 @@ int GetCdromFile(u8 *mdir, u8 *time, s8 
 				mdir = ddir;
 			}
 		} else {
-			if (!strnicmp((char *)&dir->name[0], filename, strlen(filename))) {
+			if (!strncasecmp((char *)&dir->name[0], filename, strlen(filename))) {
 				mmssdd(dir->extent, (char *)time);
 				break;
 			}
