$NetBSD: patch-libntp_timexsup.c,v 1.1 2020/06/21 15:10:47 taca Exp $

* Changes from NetBSD base.

--- libntp/timexsup.c.orig	2020-03-03 23:41:29.000000000 +0000
+++ libntp/timexsup.c
@@ -11,6 +11,7 @@
 #include <math.h>
 
 #ifdef HAVE_SYS_TIMEX_H
+# include <time.h>
 # include <sys/timex.h>
 #endif
 
