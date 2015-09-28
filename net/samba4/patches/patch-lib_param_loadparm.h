$NetBSD: patch-lib_param_loadparm.h,v 1.1 2015/09/28 17:37:04 ryoon Exp $

* Fix NetBSD build.

--- lib/param/loadparm.h.orig	2015-07-21 09:47:48.000000000 +0000
+++ lib/param/loadparm.h
@@ -31,6 +31,9 @@
 #define _LOADPARM_H
 
 #include <talloc.h>
+#if defined(__NetBSD__)
+#include <sys/time.h>
+#endif
 #include "../lib/util/parmlist.h"
 
 /* the following are used by loadparm for option lists */
