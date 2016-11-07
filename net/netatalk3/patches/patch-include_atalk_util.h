$NetBSD: patch-include_atalk_util.h,v 1.2 2016/11/07 12:46:52 christos Exp $

Make symbols loaded from dso's available to others.

--- include/atalk/util.h.orig	2014-08-07 07:11:55.000000000 -0400
+++ include/atalk/util.h	2016-11-06 09:33:20.246331563 -0500
@@ -115,7 +115,7 @@
  * OpenBSD currently does not use the second arg for dlopen(). For
  * future compatibility we define DL_LAZY */
 #ifdef __NetBSD__
-#define mod_open(a)      dlopen(a, RTLD_LAZY)
+#define mod_open(a)      dlopen(a, RTLD_LAZY|RTLD_GLOBAL)
 #elif defined(__OpenBSD__)
 #define mod_open(a)      dlopen(a, DL_LAZY)
 #else /* ! __NetBSD__ && ! __OpenBSD__ */
