$NetBSD: patch-panel-plugin_net.c,v 1.2 2019/08/19 01:19:31 gutteridge Exp $

Fix MacOS build.

--- panel-plugin/net.c.orig	2017-11-29 08:57:40.000000000 +0000
+++ panel-plugin/net.c
@@ -49,8 +49,8 @@
 # include "wormulon/hpux.h"
 # include "wormulon/hpux.c"
 #elif defined(__APPLE__)
-# include "src/macos.h"
-# include "src/macos.c"
+# include "wormulon/macos.h"
+# include "wormulon/macos.c"
 #elif (defined(__FreeBSD__) || defined(__DragonFly__) || defined(__FreeBSD_kernel__))
 # include "wormulon/freebsd.h"
 # include "wormulon/freebsd.c"
