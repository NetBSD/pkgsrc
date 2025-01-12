$NetBSD: patch-src_logo_builtin.c,v 1.1 2025/01/12 11:07:38 vins Exp $

* Include netbsd_small logo.
* Use red instead of magenta as default highlight color.  

--- src/logo/builtin.c.orig	2025-01-09 01:02:12.000000000 +0000
+++ src/logo/builtin.c
@@ -3078,10 +3078,21 @@ static const FFlogo N[] = {
         .names = {"netbsd"},
         .lines = FASTFETCH_DATATEXT_LOGO_NETBSD,
         .colors = {
-            FF_COLOR_FG_MAGENTA,
+            FF_COLOR_FG_RED,
             FF_COLOR_FG_WHITE,
         },
-        .colorKeys = FF_COLOR_FG_MAGENTA,
+        .colorKeys = FF_COLOR_FG_RED,
+        .colorTitle = FF_COLOR_FG_WHITE,
+    },
+    // NetBSDSmall
+    {
+        .names = {"netbsd_small"},
+        .lines = FASTFETCH_DATATEXT_LOGO_NETBSD_SMALL,
+        .colors = {
+            FF_COLOR_FG_RED,
+            FF_COLOR_FG_WHITE,
+        },
+        .colorKeys = FF_COLOR_FG_RED,
         .colorTitle = FF_COLOR_FG_WHITE,
     },
     // Nobara
