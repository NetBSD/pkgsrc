$NetBSD: patch-src_tcpprep.c,v 1.1 2013/10/31 02:25:17 minskim Exp $

--- src/tcpprep.c.orig	2010-04-05 00:58:02.000000000 +0000
+++ src/tcpprep.c
@@ -61,7 +61,9 @@
 #include "lib/tree.h"
 #include "tree.h"
 #include "lib/sll.h"
+#ifndef HAVE_STRLCPY
 #include "lib/strlcpy.h"
+#endif
 
 /*
  * global variables
