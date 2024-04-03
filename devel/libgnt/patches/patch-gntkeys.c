$NetBSD: patch-gntkeys.c,v 1.1 2024/04/03 21:36:16 wiz Exp $

Extend screen hack to tmux*.

--- gntkeys.c.orig	2020-06-10 02:21:05.000000000 +0000
+++ gntkeys.c
@@ -56,7 +56,7 @@ void gnt_init_keys()
 		gnt_key_cdown  = "\033" "[1;5B";
 		gnt_key_cright = "\033" "[1;5C";
 		gnt_key_cleft  = "\033" "[1;5D";
-	} else if (strstr(term, "screen") == term || strcmp(term, "rxvt-unicode") == 0) {
+	} else if (strstr(term, "screen") == term || strcmp(term, "rxvt-unicode") == 0 || strncmp(term, "tmux", 4) == 0) {
 		gnt_key_cup    = "\033" "Oa";
 		gnt_key_cdown  = "\033" "Ob";
 		gnt_key_cright = "\033" "Oc";
@@ -162,7 +162,7 @@ void gnt_keys_refine(char *text)
 	if (*text == 27 && *(text + 1) == '[' &&
 			(*(text + 2) >= 'A' && *(text + 2) <= 'D')) {
 		/* Apparently this is necessary for urxvt and screen and xterm */
-		if (strstr(term, "screen") == term || strcmp(term, "rxvt-unicode") == 0 ||
+		if (strstr(term, "screen") == term || strcmp(term, "rxvt-unicode") == 0 || strncmp(term, "tmux", 4) == 0 || 
 				strstr(term, "xterm") == term ||
 				strstr(term, "vt100") == term)
 			*(text + 1) = 'O';
