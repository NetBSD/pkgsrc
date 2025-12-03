$NetBSD: patch-popupwin.c,v 1.3 2025/12/03 22:52:01 morr Exp $

Fix Tiger build.

--- src/popupwin.c.orig	2025-12-03 21:01:37.000000000 +0000
+++ src/popupwin.c
@@ -4774,7 +4774,9 @@ popup_hide_info(void)
 
     if (wp != NULL)
     {
+#ifdef HAS_MESSAGE_WINDOW
 	popup_on_cmdline = wp->w_popup_flags & POPF_ON_CMDLINE;
+#endif
 	popup_hide(wp);
     }
 }
@@ -4798,7 +4800,11 @@ popup_close_info(void)
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
