$NetBSD: patch-window.c,v 1.1 2025/10/12 19:34:38 mrg Exp $

Include <sys/select.h> on NetBSD for select() prototype and also give
an atom a type (Atom), for GCC 14.


--- window.c.orig	2005-02-27 16:42:39.000000000 -0800
+++ window.c	2025-10-12 12:20:48.231111513 -0700
@@ -22,7 +22,7 @@
 #include <stropts.h>
 #include <poll.h>
 #endif
-#ifdef _AIX
+#if defined(_AIX) || defined(__NetBSD__)
 #include <sys/select.h>
 #endif
 
@@ -209,7 +209,7 @@ static void cleanUpImage(Display *disp, 
 static void setViewportColormap(Display *disp, int scrn, Visual *visual)
 {
 	XSetWindowAttributes swa;
-	static cmap_atom = None;
+	static Atom cmap_atom = None;
 	Window cmap_windows[2];
 
 	if (cmap_atom == None)
