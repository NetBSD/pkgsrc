$NetBSD: patch-src_daemon_common.h,v 1.1 2017/11/21 15:18:23 fhajny Exp $

Need kstat.h if available.

--- src/daemon/common.h.orig	2017-11-18 09:03:27.350750556 +0000
+++ src/daemon/common.h
@@ -32,6 +32,10 @@
 
 #include "plugin.h"
 
+#if HAVE_KSTAT_H
+#include <kstat.h>
+#endif
+
 #if HAVE_PWD_H
 #include <pwd.h>
 #endif
