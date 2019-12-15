$NetBSD: patch-net_tap-solaris.c,v 1.2 2019/12/15 18:35:25 adam Exp $

Requires qemu-common.h.

--- net/tap-solaris.c.orig	2019-12-12 18:20:48.000000000 +0000
+++ net/tap-solaris.c
@@ -23,6 +23,7 @@
  */
 
 #include "qemu/osdep.h"
+#include "qemu-common.h"
 #include "qapi/error.h"
 #include "tap_int.h"
 #include "qemu/ctype.h"
