--- util/misc.c.orig	2013-06-23 11:14:52.000000000 +0200
+++ util/misc.c	2013-06-23 11:16:27.000000000 +0200
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
