$NetBSD: patch-pico_osdep_terminal.c,v 1.1 2023/02/26 20:39:49 vins Exp $

Support Rxvt builtin keypad sequences.

--- pico/osdep/terminal.c.orig	2022-06-03 00:14:00.491274749 +0000
+++ pico/osdep/terminal.c
@@ -188,6 +188,12 @@ setup_dflt_esc_seq(void)
     kpinsert("\033[H", KEY_HOME, 1);
     kpinsert("\033[F", KEY_END, 1);
 
+    /*
+     * rxvt
+     */
+    kpinsert("\033[7~", KEY_HOME, 1);
+    kpinsert("\033[8~", KEY_END, 1);
+
     /* 
      * gnome-terminal 2.6.0, don't know why it
      * changed from 2.2.1
