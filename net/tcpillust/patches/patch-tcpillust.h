$NetBSD: patch-tcpillust.h,v 1.1 2022/04/24 22:57:52 tnn Exp $

we really don't care about pre-C89

--- tcpillust.h.orig	2000-04-21 17:31:27.000000000 +0000
+++ tcpillust.h
@@ -70,6 +70,10 @@
 #define CANVAS_HEIGHT_RATIO 2
 #define SUBCANVAS_HEIGHT_RATIO 4
 
+#ifndef __P
+#define __P(protos) protos
+#endif
+
 int zoomout_clib __P((ClientData, Tcl_Interp *, int, char **));
 int zoomin_clib __P((ClientData, Tcl_Interp *, int, char **));
 int subzoomout_clib __P((ClientData, Tcl_Interp *, int, char **));
