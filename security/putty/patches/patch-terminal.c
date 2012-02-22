$NetBSD: patch-terminal.c,v 1.1 2012/02/22 15:27:16 wiz Exp $

Make the home/end keys work on BSD servers as well as Linux ones

--- terminal.c.orig	2011-07-16 11:27:05.000000000 +0000
+++ terminal.c
@@ -6202,13 +6202,6 @@ void term_key(Terminal *term, Key_Sym ke
 	    }
 	}
 
-	/* RXVT Home/End */
-	if (term->cfg.rxvt_homeend &&
-	    (keysym == PK_HOME || keysym == PK_END)) {
-	    p += sprintf((char *) p, keysym == PK_HOME ? "\x1B[H" : "\x1BOw");
-	    goto done;
-	}
-
 	if (term->vt52_mode) {
 	    int xkey;
 
@@ -6229,11 +6222,23 @@ void term_key(Terminal *term, Key_Sym ke
 	    goto done;
 	}
 
+	/* Home/End */
+	if (keysym == PK_HOME || keysym == PK_END) {
+	    /* Send the correct XTerm or rxvt codes for home/end
+	     * We used to send ^[1~ and [4~ for Xterm,
+	     * but those are Linux console */
+	    const char *he;
+	    if (term->cfg.rxvt_homeend)
+		he = keysym == PK_HOME ? "\x1B[7~" : "\x1B[8~";
+	    else
+		he = keysym == PK_HOME ? "\x1BOH" : "\x1BOF";
+	    p += sprintf((char *) p, he);
+	    goto done;
+	}
+
 	switch (keysym) {
-	  case PK_HOME:     code = 1; break;
 	  case PK_INSERT:   code = 2; break;
 	  case PK_DELETE:   code = 3; break;
-	  case PK_END:      code = 4; break;
 	  case PK_PAGEUP:   code = 5; break;
 	  case PK_PAGEDOWN: code = 6; break;
 	  default: code = 0; break; /* else gcc warns `enum value not used' */
