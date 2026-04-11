$NetBSD: patch-term.h,v 1.1 2026/04/11 21:19:21 christos Exp $

--- term.h.orig	2010-09-02 02:12:26.000000000 -0400
+++ term.h	2026-04-11 17:02:03.362870720 -0400
@@ -2,6 +2,9 @@
  */
 /* This software is copyrighted as detailed in the LICENSE file. */
 
+#include <termcap.h>
+#include <sys/ioctl.h>
+
 
 EXT char ERASECH;		/* rubout character */
 EXT char KILLCH;		/* line delete character */
