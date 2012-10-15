$NetBSD: patch-scanner.c,v 1.1 2012/10/15 22:48:02 drochner Exp $

--- scanner.c.orig	2012-10-15 18:40:13.000000000 +0000
+++ scanner.c
@@ -26,6 +26,7 @@
 #include <sys/stat.h>
 #include <sys/time.h>
 #include <sys/resource.h>
+#include <limits.h>
 
 #include "config.h"
 
