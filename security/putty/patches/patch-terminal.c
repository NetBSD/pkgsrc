$NetBSD: patch-terminal.c,v 1.6 2023/02/14 03:28:07 ryoon Exp $

Make the home/end keys work on BSD servers as well as Linux ones

--- terminal/terminal.c.orig	2022-10-28 17:19:48.000000000 +0000
+++ terminal/terminal.c
@@ -7508,8 +7508,17 @@ int format_small_keypad_key(char *buf, T
         } else {
             p += sprintf(p, "\x1B[%c", codes[code-1]);
         }
-    } else if ((code == 1 || code == 4) && term->rxvt_homeend) {
-        p += sprintf(p, code == 1 ? "\x1B[H" : "\x1BOw");
+    } else if (code == 1 || code == 4) {
+	/* Home/End */
+	/* Send the correct XTerm or rxvt codes for home/end
+	 * We used to send ^[1~ and [4~ for Xterm,
+	 * but those are Linux console */
+	const char *he;
+	if (term->rxvt_homeend)
+	    he = code == 1 ? "\x1B[7~" : "\x1B[8~";
+	else
+	    he = code == 1 ? "\x1BOH" : "\x1BOF";
+	p += sprintf((char *) p, "%s", he);
     } else {
         if (term->vt52_mode) {
 	    p += sprintf(p, "\x1B[%d~", code);
