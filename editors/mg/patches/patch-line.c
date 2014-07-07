$NetBSD: patch-line.c,v 1.1 2014/07/07 18:06:58 jperkin Exp $

Include limits.h for INT_{MIN,MAX}

--- line.c.orig	2011-01-20 04:36:13.000000000 +0000
+++ line.c
@@ -20,6 +20,7 @@
 
 #include "def.h"
 
+#include <limits.h>
 #include <stdlib.h>
 #include <string.h>
 
