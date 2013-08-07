$NetBSD: patch-windows_window.c,v 1.2 2013/08/07 11:06:39 drochner Exp $

Make the home/end keys work on BSD servers as well as Linux ones

--- windows/window.c.orig	2013-08-04 19:32:10.000000000 +0000
+++ windows/window.c
@@ -4520,9 +4520,17 @@ static int TranslateKey(UINT message, WP
 		p += sprintf((char *) p, "\x1BO%c", code + 'P' - 11);
 	    return p - output;
 	}
-	if ((code == 1 || code == 4) &&
-	    conf_get_int(conf, CONF_rxvt_homeend)) {
-	    p += sprintf((char *) p, code == 1 ? "\x1B[H" : "\x1BOw");
+	/* Home/End */
+	if (code == 1 || code == 4) {
+	    /* Send the correct XTerm or rxvt codes for home/end
+	     * We used to send ^[1~ and [4~ for Xterm,
+             * but those are Linux console */
+	    const char *he;
+	    if (conf_get_int(conf, CONF_rxvt_homeend))
+		he = code == 1 ? "\x1B[7~" : "\x1B[8~";
+	    else
+		he = code == 1 ? "\x1BOH" : "\x1BOF";
+	    p += sprintf((char *) p, he);
 	    return p - output;
 	}
 	if (code) {
