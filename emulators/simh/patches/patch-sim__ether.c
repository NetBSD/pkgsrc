$NetBSD: patch-sim__ether.c,v 1.1 2016/12/18 11:11:28 hans Exp $

SunOS needs sys/ioctl.h for FIONBIO definition.

--- sim_ether.c.orig	2016-11-22 10:24:26.000000000 +0100
+++ sim_ether.c
@@ -366,6 +366,7 @@
 */
 
 #include <ctype.h>
+#include <sys/ioctl.h>
 #include "sim_ether.h"
 #include "sim_sock.h"
 #include "sim_timer.h"
