$NetBSD: patch-protocol.c,v 1.1.2.2 2011/12/07 08:30:52 tron Exp $

--- protocol.c.orig	2011-12-05 20:27:50.000000000 +0000
+++ protocol.c
@@ -21,6 +21,7 @@
 #include <X11/cursorfont.h>
 #include <sys/time.h>
 #include <stdio.h>
+#include <stdlib.h>
 
 #include "xpaint.h"
 #include "misc.h"
