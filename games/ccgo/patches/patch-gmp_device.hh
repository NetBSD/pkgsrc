$NetBSD: patch-gmp_device.hh,v 1.1 2016/12/17 23:22:30 joerg Exp $

--- gmp/device.hh.orig	2015-11-20 13:38:41.000000000 +0000
+++ gmp/device.hh
@@ -10,7 +10,6 @@
 #ifndef GMP_DEVICE_HH
 #define GMP_DEVICE_HH
 #include "gmp.hh"
-#include <sigc++/object.h>
 #include <sigc++/signal.h>
 #include <string>
 #include <queue>
