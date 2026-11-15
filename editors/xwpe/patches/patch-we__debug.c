$NetBSD: patch-we__debug.c,v 1.1 2026/11/15 13:14:45 vins Exp $

With neither Xft nor Cairo there is no back buffer, so this Expose
handler has nothing to copy from.  Repaint the area instead, which is
what we_xterm.c does at its own Expose case.

--- we_debug.c.orig
+++ we_debug.c
@@ -1266,10 +1266,19 @@
    }
    else if (_ev.type == Expose)
    {
-    XCopyArea(WpeXInfo.display, WpeXInfo.backbuf, WpeXInfo.window,
-      WpeXInfo.gc, _ev.xexpose.x, _ev.xexpose.y,
-      _ev.xexpose.width, _ev.xexpose.height,
-      _ev.xexpose.x, _ev.xexpose.y);
+    if (WpeXInfo.backbuf)
+     XCopyArea(WpeXInfo.display, WpeXInfo.backbuf, WpeXInfo.window,
+       WpeXInfo.gc, _ev.xexpose.x, _ev.xexpose.y,
+       _ev.xexpose.width, _ev.xexpose.height,
+       _ev.xexpose.x, _ev.xexpose.y);
+    else
+    {
+     e_refresh_area(_ev.xexpose.x / WpeXInfo.font_width,
+                    _ev.xexpose.y / WpeXInfo.font_height,
+                    _ev.xexpose.width / WpeXInfo.font_width + 2,
+                    _ev.xexpose.height / WpeXInfo.font_height + 2);
+     e_refresh();
+    }
    }
   }
  }
