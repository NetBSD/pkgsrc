$NetBSD: patch-include_atalk_util.h,v 1.2 2025/08/12 18:22:55 hauke Exp $

There is a "special" hack in util.h that makes NetBSD load modules
with RTLD_LAZY. Well, yes this appears to work, but does not really
work since symbols from pam don't get resolved. 

From PR pkg/59509

--- include/atalk/util.h.orig	2025-08-05 13:56:32.000000000 +0000
+++ include/atalk/util.h
@@ -124,7 +124,7 @@ extern void mod_close(void *);
  * OpenBSD currently does not use the second arg for dlopen(). For
  * future compatibility we define DL_LAZY */
 #ifdef __NetBSD__
-#define mod_open(a)      dlopen(a, RTLD_LAZY)
+#define mod_open(a)      dlopen(a, RTLD_NOW|RTLD_GLOBAL)
 #elif defined(__OpenBSD__)
 #define mod_open(a)      dlopen(a, DL_LAZY)
 #else /* ! __NetBSD__ && ! __OpenBSD__ */
