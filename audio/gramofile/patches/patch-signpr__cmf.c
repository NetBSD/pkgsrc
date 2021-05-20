$NetBSD: patch-signpr__cmf.c,v 1.1 2021/05/20 19:24:15 nia Exp $

include missing header for strlen().

--- signpr_cmf.c.orig	2000-11-26 00:56:00.000000000 +0000
+++ signpr_cmf.c
@@ -31,6 +31,7 @@
 #include "yesnowindow.h"
 #endif
 #include <stdlib.h>
+#include <string.h>
 #include <stdio.h>
 #include <math.h>
 #ifndef SWIG
