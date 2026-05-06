$NetBSD: patch-popupwin.c,v 1.4 2026/05/06 20:26:50 morr Exp $

Fix Tiger build.

--- src/popupwin.c.orig	2026-05-06 18:17:00.000000000 +0000
+++ src/popupwin.c
@@ -5892,7 +5892,9 @@ popup_hide_info(void)
 
     if (wp != NULL)
     {
+#ifdef HAS_MESSAGE_WINDOW
 	popup_on_cmdline = wp->w_popup_flags & POPF_ON_CMDLINE;
+#endif
 	popup_hide(wp);
 	if (State & MODE_CMDLINE)
 	    // Cmdline mode doesn't normally call update_screen(), so it's
@@ -5920,7 +5922,11 @@ popup_close_info(void)
     int
 popup_overlaps_cmdline(void)
 {
+#ifdef HAS_MESSAGE_WINDOW
     return popup_on_cmdline;
+#else
+    return 0;
+#endif
 }
 
 #if defined(HAS_MESSAGE_WINDOW)
