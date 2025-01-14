$NetBSD: patch-src_input.c,v 1.1 2025/01/14 14:40:47 ktnb Exp $

Update error setting to slang 2

--- src/input.c.orig	2001-06-20 09:43:39.000000000 +0000
+++ src/input.c
@@ -2262,7 +2262,7 @@ key_slang (buffer * buf)
     SLang_load_string (cmd);
     /* to avoid slang stack overflows... */
     SLang_restart (1);
-    SLang_Error = 0;
+    SLang_set_error (0);
 
     /* 
      * This is not the nicest thing to do, but certain slang commnds,
