$NetBSD: patch-util_misc.c,v 1.2 2013/06/23 09:45:52 obache Exp $

* prevent to crash, as PR pkg/47777
  taken from Red Hat Bug 199770:
    https://bugzilla.redhat.com/show_bug.cgi?id=199770
  upstream bug #668:
    http://sourceforge.net/p/nedit/bugs/668/

--- util/misc.c.orig	2004-08-09 22:20:00.000000000 +0000
+++ util/misc.c
@@ -383,7 +383,10 @@ Boolean FindBestVisual(Display *display,
 	*colormap = cachedColormap;
 	return (*visual == DefaultVisual(display, screen));
     }
-    
+
+    /* Set "Default" visual to avoid crashes with the detected best ones */
+    reqID = DefaultVisual(display, screen)->visualid;
+
     /* Read the visualID and installColormap resources for the application.
        visualID can be specified either as a number (the visual id as
        shown by xdpyinfo), as a visual class name, or as Best or Default. */
