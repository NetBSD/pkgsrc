$NetBSD: patch-src_console-xlike-inc.h,v 1.1 2018/01/30 11:47:39 hauke Exp $

On some target platforms, Xm headers #define *_XFT_ symbols

--- src/console-xlike-inc.h.orig	2013-08-21 17:43:45.000000000 +0000
+++ src/console-xlike-inc.h
@@ -115,6 +115,11 @@ along with XEmacs.  If not, see <http://
 #define USE_XFT_MENUBARS
 #define USE_XFT_TABS
 #define USE_XFT_GAUGES
+#else /* Xm headers might #define *_XFT */
+#undef USE_XFT
+#undef USE_XFT_MENUBARS
+#undef USE_XFT_TABS
+#undef USE_XFT_GAUGES
 #endif
 
 /***************************************************************************/
