$NetBSD: patch-windows_window.c,v 1.1 2012/02/22 15:27:17 wiz Exp $

Make the home/end keys work on BSD servers as well as Linux ones

--- windows/window.c.orig	2011-07-16 11:26:19.000000000 +0000
+++ windows/window.c
@@ -4302,8 +4302,17 @@ static int TranslateKey(UINT message, WP
 		p += sprintf((char *) p, "\x1BO%c", code + 'P' - 11);
 	    return p - output;
 	}
-	if (cfg.rxvt_homeend && (code == 1 || code == 4)) {
-	    p += sprintf((char *) p, code == 1 ? "\x1B[H" : "\x1BOw");
+	/* Home/End */
+	if (code == 1 || code == 4) {
+	    /* Send the correct XTerm or rxvt codes for home/end
+	     * We used to send ^[1~ and [4~ for Xterm,
+             * but those are Linux console */
+	    const char *he;
+	    if (cfg.rxvt_homeend)
+		he = code == 1 ? "\x1B[7~" : "\x1B[8~";
+	    else
+		he = code == 1 ? "\x1BOH" : "\x1BOF";
+	    p += sprintf((char *) p, he);
 	    return p - output;
 	}
 	if (code) {
