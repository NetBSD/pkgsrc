$NetBSD: patch-terminal.c,v 1.4 2019/04/01 12:10:43 ryoon Exp $

Make the home/end keys work on BSD servers as well as Linux ones

--- terminal.c.orig	2019-03-31 15:56:54.023245872 +0000
+++ terminal.c
@@ -6746,8 +6746,17 @@ int format_small_keypad_key(char *buf, T
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
+	p += sprintf((char *) p, he);
     } else {
         p += sprintf(p, "\x1B[%d~", code);
     }
