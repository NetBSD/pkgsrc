$NetBSD: patch-unix_gtkwin.c,v 1.1.2.2 2012/02/23 15:53:56 tron Exp $

Make the home/end keys work on BSD servers as well as Linux ones

--- unix/gtkwin.c.orig	2011-05-07 10:57:19.000000000 +0000
+++ unix/gtkwin.c
@@ -1033,9 +1033,17 @@ gint key_event(GtkWidget *widget, GdkEve
 		use_ucsoutput = FALSE;
 		goto done;
 	    }
-	    if (inst->cfg.rxvt_homeend && (code == 1 || code == 4)) {
-		end = 1 + sprintf(output+1, code == 1 ? "\x1B[H" : "\x1BOw");
-		use_ucsoutput = FALSE;
+	    /* Home/End */
+	    if (code == 1 || code == 4) {
+		/* Send the correct XTerm or rxvt codes for home/end
+		 * We used to send ^[1~ and [4~ for Xterm,
+		 * but those are Linux console */
+		const char *he;
+		if (inst->cfg.rxvt_homeend)
+		    he = code == 1 ? "\x1B[7~" : "\x1B[8~";
+		else
+		    he = code == 1 ? "\x1BOH" : "\x1BOF";
+		end = 1 + sprintf(output+1, he);
 		goto done;
 	    }
 	    if (code) {
