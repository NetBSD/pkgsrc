$NetBSD: patch-lunch.c,v 1.1 2021/12/30 00:43:35 nia Exp $

Need string.h for strlen().

--- lunch.c.orig	1997-04-28 01:34:27.000000000 +0000
+++ lunch.c
@@ -7,6 +7,7 @@
 
 #include <stdio.h>
 #include <stdlib.h>
+#include <string.h>
 #include <X11/X.h>
 #include <X11/Xlib.h>
 #include "trippy.h"
