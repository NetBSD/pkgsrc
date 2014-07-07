$NetBSD: patch-basic.c,v 1.1 2014/07/07 18:06:58 jperkin Exp $

Include limits.h for INT_{MIN,MAX}

--- basic.c.orig	2011-01-02 22:57:56.000000000 +0000
+++ basic.c
@@ -14,6 +14,7 @@
 #include "def.h"
 
 #include <ctype.h>
+#include <limits.h>
 
 /*
  * Go to beginning of line.
