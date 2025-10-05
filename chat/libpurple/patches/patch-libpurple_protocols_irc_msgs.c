$NetBSD: patch-libpurple_protocols_irc_msgs.c,v 1.1 2025/10/05 16:01:15 wiz Exp $

Fix -Wchar-subscripts in ctype(3) functions

--- libpurple/protocols/irc/msgs.c~	2024-09-17 10:52:23.000000000 +0200
+++ libpurple/protocols/irc/msgs.c	2025-10-05 15:12:52.281588294 +0200
@@ -149,8 +149,8 @@
 		/* Check for 3-digit numeric in second position */
 		if (i == 1) {
 			if (end - cur != 3
-			    || !isdigit(cur[0]) || !isdigit(cur[1])
-			    || !isdigit(cur[2])) {
+			    || !isdigit((unsigned char)cur[0]) || !isdigit((unsigned char)cur[1])
+			    || !isdigit((unsigned char)cur[2])) {
 				goto undirected;
 			}
 			/* Save the numeric for printing to the channel */
