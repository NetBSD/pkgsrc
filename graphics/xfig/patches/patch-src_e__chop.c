$NetBSD: patch-src_e__chop.c,v 1.2 2017/10/04 11:58:45 wiz Exp $

Remove unportable header.
https://sourceforge.net/p/mcj/tickets/16/

--- src/e_chop.c.orig	2016-07-23 21:10:27.000000000 +0000
+++ src/e_chop.c
@@ -19,9 +19,6 @@
 /* >>>>>>>>>>>>>>>>>>> fixme -- don't forget undo ! <<<<<<<<<<<<<<<< */
 
 #include <stdlib.h>
-#ifndef __FreeBSD__
-#include <alloca.h>
-#endif
 #include <math.h>
 #include "fig.h"
 #include "resources.h"
