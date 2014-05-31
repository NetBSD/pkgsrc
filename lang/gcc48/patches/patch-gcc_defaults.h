$NetBSD: patch-gcc_defaults.h,v 1.1 2014/05/31 13:06:25 ryoon Exp $

--- gcc/defaults.h.orig	2013-01-10 20:38:27.000000000 +0000
+++ gcc/defaults.h
@@ -1404,6 +1404,10 @@ see the files COPYING3 and COPYING.RUNTI
 #define SWITCHABLE_TARGET 0
 #endif
 
+#ifndef PIE_DEFAULT
+#define PIE_DEFAULT 0
+#endif
+
 #endif /* GCC_INSN_FLAGS_H  */
 
 #endif  /* ! GCC_DEFAULTS_H */
