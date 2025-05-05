$NetBSD: patch-popupwin.c,v 1.1 2025/05/05 15:05:27 schmonz Exp $

Fix Tiger build.

--- src/popupwin.c.orig	2025-03-15 09:19:48.000000000 +0000
+++ src/popupwin.c
@@ -4567,7 +4567,9 @@ popup_hide_info(void)
 
     if (wp != NULL)
     {
+#ifdef HAS_MESSAGE_WINDOW
 	popup_on_cmdline = wp->w_popup_flags & POPF_ON_CMDLINE;
+#endif
 	popup_hide(wp);
     }
 }
@@ -4578,7 +4580,11 @@ popup_hide_info(void)
     int
 popup_overlaps_cmdline(void)
 {
+#ifdef HAS_MESSAGE_WINDOW
     return popup_on_cmdline;
+#else
+    return 0;
+#endif
 }
 
 /*
