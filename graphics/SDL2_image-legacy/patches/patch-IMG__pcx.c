$NetBSD: patch-IMG__pcx.c,v 1.1 2024/05/06 18:05:32 nia Exp $

Fix CVE-2018-3837. Taken from Ubuntu Linux.

--- IMG_pcx.c.orig	2016-01-03 05:52:28.000000000 +0000
+++ IMG_pcx.c
@@ -149,7 +149,7 @@ SDL_Surface *IMG_LoadPCX_RW(SDL_RWops *s
     if (bpl > surface->pitch) {
         error = "bytes per line is too large (corrupt?)";
     }
-    buf = (Uint8 *)SDL_malloc(bpl);
+    buf = (Uint8 *)SDL_calloc(SDL_max(bpl, surface->pitch), 1);
     row = (Uint8 *)surface->pixels;
     for ( y=0; y<surface->h; ++y ) {
         /* decode a scan line to a temporary buffer first */
