$NetBSD: patch-gdk_gdkglshapes.c,v 1.1 2018/06/03 23:53:03 dholland Exp $

Work around namespace conflict with archaic index() in strings.h.
No idea why this broke suddenly in 2018, as opposed to, say, twenty
years ago.

--- gdk/gdkglshapes.c~	2004-02-20 09:38:12.000000000 +0000
+++ gdk/gdkglshapes.c
@@ -31,6 +31,9 @@
 #include <GL/gl.h>
 #include <GL/glu.h>
 
+/* workaround for namespace pollution */
+#define index index_
+
 /* 
  * The following code is imported from GLUT.
  */
