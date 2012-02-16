$NetBSD: patch-.._spunk_xsrc_screen.cc,v 1.1 2012/02/16 16:47:58 hans Exp $

--- ../spunk/xsrc/screen.cc.orig	1996-11-07 18:06:58.000000000 +0100
+++ ../spunk/xsrc/screen.cc	2012-01-25 18:43:41.244123272 +0100
@@ -21,6 +21,10 @@
 
 #include <string.h>
 
+#ifdef __sun
+#include <alloca.h>
+#endif
+
 #include "../cont.h"
 #include "../winattr.h"
 #include "../environ.h"
