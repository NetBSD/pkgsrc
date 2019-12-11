$NetBSD: patch-net_tap-solaris.c,v 1.1 2019/12/11 16:44:22 jperkin Exp $

Requires qemu-common.h.

--- net/tap-solaris.c.orig	2019-08-15 19:01:42.000000000 +0000
+++ net/tap-solaris.c
@@ -23,6 +23,7 @@
  */
 
 #include "qemu/osdep.h"
+#include "qemu-common.h"
 #include "qapi/error.h"
 #include "tap_int.h"
 #include "sysemu/sysemu.h"
