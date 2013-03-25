$NetBSD: patch-draw_3d.c,v 1.1 2013/03/25 01:59:03 dholland Exp $

--- draw_3d.c~	1994-04-15 10:57:35.000000000 +0000
+++ draw_3d.c
@@ -9,6 +9,7 @@
 #include <stdio.h>
 #include <math.h>
 #include <stdlib.h>
+#include <string.h>
 #include "trigtab.h"
 #include "netmaze.h"
 
