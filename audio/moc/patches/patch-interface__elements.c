$NetBSD: patch-interface__elements.c,v 1.1 2017/01/30 04:19:22 maya Exp $

don't attempt to set esc delay before setting a window... fails
silently for ncurses, segfaults for nbcurses.

--- interface_elements.c.orig	2014-08-30 02:31:51.000000000 +0000
+++ interface_elements.c
@@ -3622,13 +3622,6 @@ static void info_win_resize (struct info
 
 void windows_init ()
 {
-	if (getenv ("ESCDELAY") == NULL) {
-#ifdef HAVE_SET_ESCDELAY
-		set_escdelay (25);
-#else
-		setenv ("ESCDELAY", "25", 0);
-#endif
-	}
 
 	utf8_init ();
 	if (!initscr ())
@@ -3659,6 +3652,15 @@ void windows_init ()
 	wnoutrefresh (info_win.win);
 	doupdate ();
 
+	if (getenv ("ESCDELAY") == NULL) {
+#ifdef HAVE_SET_ESCDELAY
+		set_escdelay (25);
+#else
+		setenv ("ESCDELAY", "25", 0);
+#endif
+	}
+
+
 	iface_initialized = 1;
 }
 
