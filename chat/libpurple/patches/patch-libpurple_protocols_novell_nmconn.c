$NetBSD: patch-libpurple_protocols_novell_nmconn.c,v 1.1 2025/10/05 16:01:16 wiz Exp $

Fix -Wchar-subscripts in ctype(3) functions

--- libpurple/protocols/novell/nmconn.c~	2024-09-17 10:52:23.000000000 +0200
+++ libpurple/protocols/novell/nmconn.c	2025-10-05 15:13:26.469842018 +0200
@@ -512,7 +512,7 @@
 			ptr++;
 
 			i = 0;
-			while (isdigit(*ptr) && (i < 3)) {
+			while (isdigit((unsigned char)*ptr) && (i < 3)) {
 				rtn_buf[i] = *ptr;
 				i++;
 				ptr++;
