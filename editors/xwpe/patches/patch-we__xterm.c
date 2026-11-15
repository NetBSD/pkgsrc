$NetBSD: patch-we__xterm.c,v 1.2 2026/11/15 13:14:45 vins Exp $

With neither Xft nor Cairo there is no back buffer, so these three
whole-window blits after a resize have nothing to copy from.  The
repaint that follows (e_relayout_windows, e_x_repaint_desk) is what
draws in that case.

--- we_xterm.c.orig	2026-07-07 22:08:18.000000000 +0000
+++ we_xterm.c
@@ -1087,8 +1087,9 @@ int e_x_change(PIC *pic)
     { int _pw, _ph, _old_scol, _old_slns;
       if (e_x_apply_configure(&report, &_pw, &_ph, &_old_scol, &_old_slns))
       {
-       XCopyArea(WpeXInfo.display, WpeXInfo.backbuf, WpeXInfo.window,
-         WpeXInfo.gc, 0, 0, _pw, _ph, 0, 0);
+       if (WpeXInfo.backbuf)
+        XCopyArea(WpeXInfo.display, WpeXInfo.backbuf, WpeXInfo.window,
+          WpeXInfo.gc, 0, 0, _pw, _ph, 0, 0);
        e_relayout_windows(WpeEditor, _old_scol, _old_slns);
        e_x_repaint_desk(WpeEditor->f[WpeEditor->mxedt]);
       }
@@ -1266,8 +1267,9 @@ int e_x_getch()
     { int _i, _pw, _ph, _old_scol, _old_slns;
       if (e_x_apply_configure(&report, &_pw, &_ph, &_old_scol, &_old_slns))
       {
-       XCopyArea(WpeXInfo.display, WpeXInfo.backbuf, WpeXInfo.window,
-         WpeXInfo.gc, 0, 0, _pw, _ph, 0, 0);
+       if (WpeXInfo.backbuf)
+        XCopyArea(WpeXInfo.display, WpeXInfo.backbuf, WpeXInfo.window,
+          WpeXInfo.gc, 0, 0, _pw, _ph, 0, 0);
        XFlush(WpeXInfo.display);
 
        /* If the last-view pic is not a live window's, drop it: the grid (and so
@@ -1280,8 +1282,9 @@ int e_x_getch()
          if (!_is_win_pic)
           (*e_u_setlastpic)(NULL);
        }
-       XCopyArea(WpeXInfo.display, WpeXInfo.backbuf, WpeXInfo.window,
-         WpeXInfo.gc, 0, 0, _pw, _ph, 0, 0);
+       if (WpeXInfo.backbuf)
+        XCopyArea(WpeXInfo.display, WpeXInfo.backbuf, WpeXInfo.window,
+          WpeXInfo.gc, 0, 0, _pw, _ph, 0, 0);
        e_relayout_windows(WpeEditor, _old_scol, _old_slns);
        e_x_repaint_desk(WpeEditor->f[WpeEditor->mxedt]);
        return WPE_RESIZE;
