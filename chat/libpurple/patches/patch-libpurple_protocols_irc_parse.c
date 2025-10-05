$NetBSD: patch-libpurple_protocols_irc_parse.c,v 1.1 2025/10/05 16:01:15 wiz Exp $

Fix -Wchar-subscripts in ctype(3) functions

--- libpurple/protocols/irc/parse.c~	2024-10-25 09:38:45.000000000 +0200
+++ libpurple/protocols/irc/parse.c	2025-10-05 15:12:38.279670906 +0200
@@ -408,15 +408,15 @@
 		case '\003':
 			cur++;
 			fg[0] = fg[1] = bg[0] = bg[1] = '\0';
-			if (isdigit(*cur))
+			if (isdigit((unsigned char)*cur))
 				fg[0] = *cur++;
-			if (isdigit(*cur))
+			if (isdigit((unsigned char)*cur))
 				fg[1] = *cur++;
 			if (*cur == ',') {
 				cur++;
-				if (isdigit(*cur))
+				if (isdigit((unsigned char)*cur))
 					bg[0] = *cur++;
-				if (isdigit(*cur))
+				if (isdigit((unsigned char)*cur))
 					bg[1] = *cur++;
 			}
 			if (font) {
@@ -498,16 +498,16 @@
 		switch (result[i]) {
 		case '\003':
 			/* Foreground color */
-			if (isdigit(result[i + 1]))
+			if (isdigit((unsigned char)result[i + 1]))
 				i++;
-			if (isdigit(result[i + 1]))
+			if (isdigit((unsigned char)result[i + 1]))
 				i++;
 			/* Optional comma and background color */
 			if (result[i + 1] == ',') {
 				i++;
-				if (isdigit(result[i + 1]))
+				if (isdigit((unsigned char)result[i + 1]))
 					i++;
-				if (isdigit(result[i + 1]))
+				if (isdigit((unsigned char)result[i + 1]))
 					i++;
 			}
 			/* Note that i still points to the last character
