$NetBSD: patch-popupwin.c,v 1.1.2.1 2025/07/20 14:42:00 maya Exp $

Fix Tiger build.

--- src/popupwin.c.orig	2025-07-20 08:47:14.000000000 +0000
+++ src/popupwin.c
@@ -4605,7 +4605,9 @@ popup_hide_info(void)
 
     if (wp != NULL)
     {
+#ifdef HAS_MESSAGE_WINDOW
 	popup_on_cmdline = wp->w_popup_flags & POPF_ON_CMDLINE;
+#endif
 	popup_hide(wp);
     }
 }
@@ -4629,7 +4631,11 @@ popup_close_info(void)
     int
 popup_overlaps_cmdline(void)
 {
-    return popup_on_cmdline;
+#ifdef HAS_MESSAGE_WINDOW
+    return popup_on_cmdline;
+#else
+    return 0;
+#endif
 }
 
 #if defined(HAS_MESSAGE_WINDOW) || defined(PROTO)
