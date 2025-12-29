$NetBSD: patch-src_ui_common__ui.c,v 1.1 2025/12/29 03:10:14 ktnb Exp $

Comment out broken code for now. https://github.com/ravachol/kew/issues/519

--- src/ui/common_ui.c.orig	2025-12-29 02:51:24.742217846 +0000
+++ src/ui/common_ui.c
@@ -489,7 +489,7 @@ void process_name(const char *name, char
         if (strip_unneeded_chars)
                 remove_unneeded_chars(output, strnlen(output, max_width));
 
-        trim(output, strlen(output));
+//        trim(output, strlen(output));
 }
 
 void process_name_scroll(const char *name, char *output, int max_width,
