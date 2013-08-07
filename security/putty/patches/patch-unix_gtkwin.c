$NetBSD: patch-unix_gtkwin.c,v 1.3 2013/08/07 11:06:39 drochner Exp $

Make the home/end keys work on BSD servers as well as Linux ones

--- unix/gtkwin.c.orig	2013-07-20 13:15:10.000000000 +0000
+++ unix/gtkwin.c
@@ -1132,10 +1132,17 @@ gint key_event(GtkWidget *widget, GdkEve
 		use_ucsoutput = FALSE;
 		goto done;
 	    }
-	    if ((code == 1 || code == 4) &&
-		conf_get_int(inst->conf, CONF_rxvt_homeend)) {
-		end = 1 + sprintf(output+1, code == 1 ? "\x1B[H" : "\x1BOw");
-		use_ucsoutput = FALSE;
+	    /* Home/End */
+	    if (code == 1 || code == 4) {
+		/* Send the correct XTerm or rxvt codes for home/end
+		 * We used to send ^[1~ and [4~ for Xterm,
+		 * but those are Linux console */
+		const char *he;
+		if (conf_get_int(inst->conf, CONF_rxvt_homeend))
+		    he = code == 1 ? "\x1B[7~" : "\x1B[8~";
+		else
+		    he = code == 1 ? "\x1BOH" : "\x1BOF";
+		end = 1 + sprintf(output+1, "%s", he);
 		goto done;
 	    }
 	    if (code) {
