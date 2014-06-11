$NetBSD: patch-include_atalk_util.h,v 1.1 2014/06/11 11:03:57 hauke Exp $

--- include/atalk/util.h.orig	2014-01-27 07:37:46.000000000 +0000
+++ include/atalk/util.h
@@ -109,7 +109,7 @@ extern void mod_close    (void *);
  * OpenBSD currently does not use the second arg for dlopen(). For
  * future compatibility we define DL_LAZY */
 #ifdef __NetBSD__
-#define mod_open(a)      dlopen(a, RTLD_LAZY)
+#define mod_open(a)      dlopen(a, RTLD_LAZY|RTLD_GLOBAL)
 #elif defined(__OpenBSD__)
 #define mod_open(a)      dlopen(a, DL_LAZY)
 #else /* ! __NetBSD__ && ! __OpenBSD__ */
