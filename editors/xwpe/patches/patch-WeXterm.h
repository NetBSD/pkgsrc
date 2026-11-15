$NetBSD: patch-WeXterm.h,v 1.1 2026/11/15 13:14:45 vins Exp $

backbuf is not an Xft object.  The Cairo backend creates it itself, in
cr_resize(), and draws into it; Xft only happens to be the other user.
Declaring it inside #ifdef HAVE_XFT breaks every build that has X11 but
not Xft.

--- WeXterm.h.orig
+++ WeXterm.h
@@ -53,12 +53,14 @@
  int colors[16];
  WpeMouseShape shape_list[2];
  char *selection;
+ Pixmap backbuf;          /* the X11 back buffer: Xft draws into it, and so
+                             does the Cairo backend, which creates it itself
+                             in cr_resize().  It is not an Xft object. */
 #ifdef HAVE_XFT
  XftFont *xftfont;
  XftDraw *xftdraw;
  XftColor xftcolors[24];   /* 16 base + up to 8 LSP truecolor slots (we_lsp.h
                               LSP_SEM_TC_MAX): a fg index 16+slot picks a slot */
- Pixmap backbuf;
  FcPattern *xftpattern;
  FcFontSet *xftfont_set;
 #endif
