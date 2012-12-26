$NetBSD: patch-src_meta_xmeta.c,v 1.1 2012/12/26 22:31:31 dholland Exp $

- include needed X headers
- pass XFlush() its argument (hopefully the right one, but it's better
  than using uninitialized stack trash)
- declare static functions static
- declare void functions void
- avoid implicit int

--- src/meta/xmeta.c.orig	2003-11-17 02:21:53.000000000 +0000
+++ src/meta/xmeta.c
@@ -9,10 +9,14 @@ static const char	RCSid[] = "$Id: xmeta.
  *     2/26/86
  */
 
+#include <X11/Xlib.h>
+
 #include  "rtprocess.h"
 #include  "meta.h"
 #include  "plot.h"
 
+/* XXX should be in a header */
+extern Display *dpy;	/* from x11plot.c */
 
 #define  overlap(p,xmn,ymn,xmx,ymx)  (ov((p)->xy[XMN],(p)->xy[XMX],xmn,xmx) \
 				     &&ov((p)->xy[YMN],(p)->xy[YMX],ymn,ymx))
@@ -21,6 +25,8 @@ static const char	RCSid[] = "$Id: xmeta.
 
 #define  XCOM  "pexpand +OCIsv -P %s"
 
+static void doglobal(register PRIMITIVE *g, int sf);
+static void doprim(register PRIMITIVE *p, int sf);
 
 char  *progname;
 
@@ -31,7 +37,7 @@ static PLIST  recording;
 int maxalloc = 0;		/* no limit */
 
 
-
+int
 main(argc, argv)
 
 int  argc;
@@ -121,7 +127,7 @@ FILE  *infp;
 }
 
 
-
+void
 replay(xmin, ymin, xmax, ymax)		/* play back region */
 int  xmin, ymin, xmax, ymax;
 {
@@ -140,7 +146,7 @@ int  xmin, ymin, xmax, ymax;
 
 
 
-
+static void
 save(p)				/* record primitive */
 PRIMITIVE  *p;
 {
@@ -153,8 +159,7 @@ PRIMITIVE  *p;
 }
 
 
-
-
+static void
 doglobal(g, sf)			/* execute a global command */
 
 register PRIMITIVE  *g;
@@ -168,7 +173,7 @@ int  sf;
 	    return;
 
 	case PDRAW:
-	    XFlush();
+	    XFlush(dpy);
 	    break;
 
 	case PEOP:
@@ -201,8 +206,7 @@ int  sf;
 }
 
 
-
-
+static void
 doprim(p, sf)		/* plot primitive */
 
 register PRIMITIVE  *p;
