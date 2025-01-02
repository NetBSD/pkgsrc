$NetBSD: patch-unix_window.c,v 1.1 2025/01/02 17:24:57 tnn Exp $

Fix compile error. length variable missing.

--- unix/window.c.orig	2025-01-02 17:18:23.233993816 +0000
+++ unix/window.c
@@ -2961,7 +2961,7 @@ static void clipboard_text_received(GtkC
     if (!text)
         return;
 
-    paste = dup_mb_to_wc(CS_UTF8, text, length, &paste_len);
+    paste = dup_mb_to_wc_c(CS_UTF8, text, strlen(text), &paste_len);
 
     term_do_paste(inst->term, paste, paste_len);
 
