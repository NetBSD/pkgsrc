$NetBSD: patch-line.c,v 1.1 2023/02/07 20:32:34 wiz Exp $

End OSC8 hyperlink on invalid embedded escape sequence.
https://github.com/gwsw/less/commit/a78e1351113cef564d790a730d657a321624d79c

--- line.c.orig	2022-07-22 19:26:24.000000000 +0000
+++ line.c
@@ -633,8 +633,8 @@ ansi_step(pansi, ch)
 		/* Hyperlink ends with \7 or ESC-backslash. */
 		if (ch == '\7')
 			return ANSI_END;
-		if (pansi->prev_esc && ch == '\\')
-			return ANSI_END;
+		if (pansi->prev_esc)
+            		return (ch == '\\') ? ANSI_END : ANSI_ERR;
 		pansi->prev_esc = (ch == ESC);
 		return ANSI_MID;
 	}
