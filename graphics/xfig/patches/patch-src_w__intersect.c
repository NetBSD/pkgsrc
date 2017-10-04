$NetBSD: patch-src_w__intersect.c,v 1.2 2017/10/04 11:58:45 wiz Exp $

Remove unportable header.
https://sourceforge.net/p/mcj/tickets/16/

--- src/w_intersect.c.orig	2016-07-23 21:10:28.000000000 +0000
+++ src/w_intersect.c
@@ -26,7 +26,6 @@
 #include "w_msgpanel.h"
 #include "f_util.h"
 #include "u_quartic.h"
-#include <alloca.h>
 #include <math.h>
 #undef I
 
