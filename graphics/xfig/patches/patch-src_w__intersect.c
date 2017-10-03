$NetBSD: patch-src_w__intersect.c,v 1.1 2017/10/03 15:09:36 wiz Exp $

Remove unportable header.

--- src/w_intersect.c.orig	2016-07-23 21:10:28.000000000 +0000
+++ src/w_intersect.c
@@ -26,7 +26,6 @@
 #include "w_msgpanel.h"
 #include "f_util.h"
 #include "u_quartic.h"
-#include <alloca.h>
 #include <math.h>
 #undef I
 
