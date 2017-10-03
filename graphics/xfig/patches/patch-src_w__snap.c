$NetBSD: patch-src_w__snap.c,v 1.1 2017/10/03 15:09:36 wiz Exp $

Remove unportable header.

--- src/w_snap.c.orig	2016-07-23 21:10:28.000000000 +0000
+++ src/w_snap.c
@@ -32,9 +32,6 @@
 #include "u_search.h"
 #include "f_util.h"
 #include <math.h>
-#ifndef __FreeBSD__
-#include <alloca.h>
-#endif
 
 int snap_gx;
 int snap_gy;
