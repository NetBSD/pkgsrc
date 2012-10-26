$NetBSD: patch-main.c,v 1.1 2012/10/26 20:39:57 joerg Exp $

--- main.c.orig	2012-10-26 14:13:43.000000000 +0000
+++ main.c
@@ -27,6 +27,7 @@
 #include <X11/Xatom.h>
 
 #include <stdio.h>
+#include <stdlib.h>
 
 #include "defs.h"
 #include "tile.h"
