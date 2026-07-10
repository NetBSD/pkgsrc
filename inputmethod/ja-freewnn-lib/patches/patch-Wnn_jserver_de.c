$NetBSD: patch-Wnn_jserver_de.c,v 1.1 2026/07/10 23:32:37 tsutsui Exp $

- Use proper signal handler types

--- Wnn/jserver/de.c.orig	2013-09-02 11:01:39.000000000 +0000
+++ Wnn/jserver/de.c
@@ -1321,7 +1321,7 @@ js_kill (void)
     {
       put4_cur (0);
       putc_purge ();
-      terminate_hand ();
+      terminate_hand (0);
     }
   else
     {
