$NetBSD: patch-lib_stat.c,v 1.1 2017/12/30 21:59:26 schwarz Exp $

patch for MacOS Sierra. cf.
http://lists.gnu.org/archive/html/bug-gnulib/2017-11/msg00056.html

--- lib/stat.c.orig	2017-12-23 01:02:50.000000000 +0100
+++ lib/stat.c	2017-12-23 01:03:48.000000000 +0100
@@ -46,6 +46,7 @@
    eliminates this include because of the preliminary #include <sys/stat.h>
    above.  */
 #include "sys/stat.h"
+#include "stat-time.h"
 
 #include <errno.h>
 #include <limits.h>
