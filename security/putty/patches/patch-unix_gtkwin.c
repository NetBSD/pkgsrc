$NetBSD: patch-unix_gtkwin.c,v 1.4 2017/03/17 00:11:48 maya Exp $

Make the home/end keys work on BSD servers as well as Linux ones

--- unix/gtkwin.c.orig	2017-02-18 17:10:15.000000000 +0000
+++ unix/gtkwin.c
@@ -1586,13 +1586,21 @@ gint key_event(GtkWidget *widget, GdkEve
 		use_ucsoutput = FALSE;
 		goto done;
 	    }
-	    if ((code == 1 || code == 4) &&
-		conf_get_int(inst->conf, CONF_rxvt_homeend)) {
+	    /* Home/End */
+	    if (code == 1 || code == 4) {
 #ifdef KEY_EVENT_DIAGNOSTICS
                 debug((" - rxvt style Home/End"));
 #endif
-		end = 1 + sprintf(output+1, code == 1 ? "\x1B[H" : "\x1BOw");
-		use_ucsoutput = FALSE;
+		/* Send the correct XTerm or rxvt codes for home/end
+		 * We used to send ^[1~ and [4~ for Xterm,
+		 * but those are Linux console */
+		const char *he;
+		if (conf_get_int(inst->conf, CONF_rxvt_homeend))
+		    he = code == 1 ? "\x1B[7~" : "\x1B[8~";
+		else
+		    he = code == 1 ? "\x1BOH" : "\x1BOF";
+		end = 1 + sprintf(output+1, "%s", he);
+
 		goto done;
 	    }
 	    if (code) {
