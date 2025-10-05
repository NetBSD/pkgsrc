$NetBSD: patch-libpurple_protocols_zephyr_zephyr.c,v 1.1 2025/10/05 16:01:16 wiz Exp $

Fix -Wchar-subscripts in ctype(3) functions

--- libpurple/protocols/zephyr/zephyr.c~	2024-09-17 21:31:28.000000000 +0200
+++ libpurple/protocols/zephyr/zephyr.c	2025-10-05 15:14:28.248010827 +0200
@@ -627,7 +627,7 @@
 			message += 2;
 		} else if (*message == '@') {
 			int end;
-			for (end = 1; message[end] && (isalnum(message[end]) || message[end] == '_'); end++);
+			for (end = 1; message[end] && (isalnum((unsigned char)message[end]) || message[end] == '_'); end++);
 			if (message[end] &&
 			    (message[end] == '{' || message[end] == '[' || message[end] == '(' ||
 			     !g_ascii_strncasecmp(message + end, "&lt;", 4))) {
