$NetBSD: patch-src_logo_builtin.c,v 1.3 2025/02/14 10:39:17 vins Exp $

Embed the NetBSD2 alternative logo.

--- src/logo/builtin.c.orig	2025-02-11 02:40:51.000000000 +0000
+++ src/logo/builtin.c
@@ -3135,6 +3135,18 @@ static const FFlogo N[] = {
         .colorKeys = FF_COLOR_FG_RED,
         .colorTitle = FF_COLOR_FG_WHITE,
     },
+    // NetBSD2
+    {
+        .names = {"NetBSD2", "NetBSD_alt"},
+        .lines = FASTFETCH_DATATEXT_LOGO_NETBSD2,
+        .type = FF_LOGO_LINE_TYPE_ALTER_BIT,
+        .colors = {
+            FF_COLOR_FG_RED,
+            FF_COLOR_FG_WHITE,
+        },
+        .colorKeys = FF_COLOR_FG_RED,
+        .colorTitle = FF_COLOR_FG_WHITE,
+    },
     // NetBSD Small
     {
         .names = {"NetBSD_small"},
