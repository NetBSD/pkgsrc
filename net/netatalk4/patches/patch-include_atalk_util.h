$NetBSD: patch-include_atalk_util.h,v 1.1 2025/07/05 12:30:16 hauke Exp $

From PR pkg/59509: There is a "special" hack in util.h that makes
NetBSD load modules with RTLD_LAZY. Well, yes this appears to work,
but does not really work since symbols from pam don't get resolved.

--- include/atalk/util.h.orig  2025-07-04 10:23:35.330324979 -0400
+++ include/atalk/util.h       2025-07-04 10:23:50.613808953 -0400
@@ -122,7 +122,7 @@
  * OpenBSD currently does not use the second arg for dlopen(). For
  * future compatibility we define DL_LAZY */
 #ifdef __NetBSD__
-#define mod_open(a)      dlopen(a, RTLD_LAZY)
+#define mod_open(a)      dlopen(a, RTLD_NOW|RTLD_GLOBAL)
 #elif defined(__OpenBSD__)
 #define mod_open(a)      dlopen(a, DL_LAZY)
 #else /* ! __NetBSD__ && ! __OpenBSD__ */
