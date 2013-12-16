$NetBSD: patch-calendar_libedata-cal_e-cal-backend-intervaltree.c,v 1.1 2013/12/16 08:32:24 asau Exp $

--- calendar/libedata-cal/e-cal-backend-intervaltree.c.orig	2011-04-21 19:35:36.000000000 +0000
+++ calendar/libedata-cal/e-cal-backend-intervaltree.c	2013-12-16 08:17:33.117504301 +0000
@@ -26,7 +26,7 @@
 
 #include <stdio.h>
 #include <string.h>
-#include <malloc.h>
+#include <stdlib.h>
 
 #include "e-cal-backend-intervaltree.h"
 
