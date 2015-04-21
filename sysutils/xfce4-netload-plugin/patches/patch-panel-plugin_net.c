$NetBSD: patch-panel-plugin_net.c,v 1.1 2015/04/21 08:56:41 jperkin Exp $

Fix DragonFly build.
--- panel-plugin/net.c.orig	2014-11-02 11:50:26.000000000 +0000
+++ panel-plugin/net.c
@@ -48,9 +48,9 @@
 # include "wormulon/hpux.h"
 # include "wormulon/hpux.c"
 #elif __APPLE__
-# include "src/macos.h"
-# include "src/macos.c"
-#elif __FreeBSD__ || __DragonFly__ || __FreeBSD_kernel__
+# include "wormulon/macos.h"
+# include "wormulon/macos.c"
+#elif defined(__FreeBSD__) || defined(__DragonFly__) || defined(__FreeBSD_kernel__)
 # include "wormulon/freebsd.h"
 # include "wormulon/freebsd.c"
 #elif __linux__
