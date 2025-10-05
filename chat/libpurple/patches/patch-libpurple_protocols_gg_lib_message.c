$NetBSD: patch-libpurple_protocols_gg_lib_message.c,v 1.1 2025/10/05 16:01:15 wiz Exp $

Fix -Wchar-subscripts in ctype(3) functions

--- libpurple/protocols/gg/lib/message.c~	2024-09-17 10:52:23.000000000 +0200
+++ libpurple/protocols/gg/lib/message.c	2025-10-05 15:11:19.337069955 +0200
@@ -694,7 +694,7 @@
 		*format_len = 0;
 
 	for (src = html; *src != 0; src++) {
-		if (in_entity && !(isalnum(*src) || *src == '#' || *src == ';')) {
+		if (in_entity && !(isalnum((unsigned char)*src) || *src == '#' || *src == ';')) {
 			int first = 1;
 			size_t i, append_len = src - entity;
 
@@ -738,7 +738,7 @@
 					int i, ok = 1;
 
 					for (i = 0; i < 16; i++) {
-						if (!isxdigit(tag[i])) {
+						if (!isxdigit((unsigned char)tag[i])) {
 							ok = 0;
 							break;
 						}
@@ -839,7 +839,7 @@
 								break;
 
 							for (i = 0; i < 6; i++) {
-								if (!isxdigit(tag[i])) {
+								if (!isxdigit((unsigned char)tag[i])) {
 									ok = 0;
 									break;
 								}
@@ -914,7 +914,7 @@
 			continue;
 		}
 
-		if (in_entity && !(isalnum(*src) || *src == '#'))
+		if (in_entity && !(isalnum((unsigned char)*src) || *src == '#'))
 			in_entity = 0;
 
 		if (in_entity)
