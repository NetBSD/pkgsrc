$NetBSD: patch-src_variable.c,v 1.1 2017/11/03 15:00:10 adam Exp $

Add NetBSD native X and pkgsrc modular X directories to the candidate
font path list.

--- src/variable.c.orig	2013-07-03 16:31:53.000000000 +0000
+++ src/variable.c
@@ -279,6 +279,15 @@ static const struct path_table fontpath_
     { "$`kpsexpand '$TEXMFMAIN'`/fonts/type1!" },
     { "$`kpsexpand '$TEXMFDIST'`/fonts/type1!" },
 #endif
+    /* NetBSD pkgsrc X.org */
+    { @PKGSRC_PREFIX@ "/lib/X11/fonts/Type1" },
+    { @PKGSRC_PREFIX@ "/lib/X11/fonts/truetype" },
+    /* NetBSD pkgsrc default font path */
+    { @PKGSRC_PREFIX@ "/share/fonts/X11/Type1" },
+    { @PKGSRC_PREFIX@ "/share/fonts/X11/TTF" },
+    /* NetBSD native X.org */
+    { "/usr/X11R7/lib/X11/fonts/Type1" },
+    { "/usr/X11R7/lib/X11/fonts/truetype" },
     /* Linux paths */
     { "/usr/X11R6/lib/X11/fonts/Type1" },
     { "/usr/X11R6/lib/X11/fonts/truetype" },
