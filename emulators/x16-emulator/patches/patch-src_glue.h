$NetBSD: patch-src_glue.h,v 1.1 2023/05/16 06:01:45 thorpej Exp $

Squelch "passing arguments to 'machine_paste' without a prototype is
deprecated in all versions of C and is not supported in C2x" error
thrown by Apple clang version 14.0.3 (clang-1403.0.22.14.1) (Xcode 14.3).

--- src/glue.h.orig	2023-05-16 05:38:54
+++ src/glue.h	2023-05-16 05:39:19
@@ -63,7 +63,7 @@ extern void machine_paste();
 
 extern void machine_dump();
 extern void machine_reset();
-extern void machine_paste();
+extern void machine_paste(char *);
 extern void machine_toggle_warp();
 extern void init_audio();
 
