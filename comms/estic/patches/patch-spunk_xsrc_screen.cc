$NetBSD: patch-spunk_xsrc_screen.cc,v 1.1 2012/11/16 00:37:47 joerg Exp $

--- spunk/xsrc/screen.cc.orig	1996-11-07 18:06:58.000000000 +0000
+++ spunk/xsrc/screen.cc
@@ -21,6 +21,10 @@
 
 #include <string.h>
 
+#ifdef __sun
+#include <alloca.h>
+#endif
+
 #include "../cont.h"
 #include "../winattr.h"
 #include "../environ.h"
