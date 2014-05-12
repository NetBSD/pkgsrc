$NetBSD: patch-lp__utils.c,v 1.1 2014/05/12 11:41:46 ryoon Exp $

OpenBSD 5.5 has no sys/timeb.h.

--- lp_utils.c.orig	2009-08-27 19:52:00.000000000 +0000
+++ lp_utils.c
@@ -5,7 +5,9 @@
 #include "lp_lib.h"
 #include "lp_utils.h"
 #include <time.h>
+#if !defined(__OpenBSD__)
 #include <sys/timeb.h>
+#endif
 #include "lp_bit.h"
 
 #ifdef FORTIFY
