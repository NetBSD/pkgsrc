$NetBSD: patch-lp__utils.c,v 1.2 2015/12/07 17:40:27 joerg Exp $

Don't use obsolete headers.

--- lp_utils.c.orig	2009-08-27 19:52:00.000000000 +0000
+++ lp_utils.c
@@ -5,7 +5,6 @@
 #include "lp_lib.h"
 #include "lp_utils.h"
 #include <time.h>
-#include <sys/timeb.h>
 #include "lp_bit.h"
 
 #ifdef FORTIFY
