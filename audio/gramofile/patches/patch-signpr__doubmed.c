$NetBSD: patch-signpr__doubmed.c,v 1.1 2021/05/20 19:24:15 nia Exp $

include missing header for strlen().

--- signpr_doubmed.c.orig	2000-11-26 00:56:02.000000000 +0000
+++ signpr_doubmed.c
@@ -17,6 +17,7 @@
 #include "boxes.h"
 #include "helpline.h"
 #endif
+#include <string.h>
 #include <stdlib.h>
 #include <stdio.h>
 #ifndef SWIG
