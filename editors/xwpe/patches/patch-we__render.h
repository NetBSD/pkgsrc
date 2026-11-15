$NetBSD: patch-we__render.h,v 1.1 2026/11/15 13:14:45 vins Exp $

Allow X11 build without cairo/pango support.

--- we_render.h.orig
+++ we_render.h
@@ -49,7 +49,7 @@
 
 int wpe_render_cairo_init(void);
 void wpe_render_chrome(void);
-#ifdef NO_XWINDOWS
+#if defined(NO_XWINDOWS) || !defined(HAVE_CAIRO) || !defined(HAVE_PANGO)
 /* The Cairo chrome (the fluid scrollbar thumb) is X11-only; with no X11 there
    is no chrome, so these hit-tests can never match.  Inline no-op stubs let the
    shared mouse code (we_mouse.c) link in a --without-x build, where
