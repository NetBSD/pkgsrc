$NetBSD: patch-gcc_defaults.h,v 1.1 2014/01/25 13:38:48 ryoon Exp $

--- gcc/defaults.h.orig	2010-11-29 14:09:41.000000000 +0000
+++ gcc/defaults.h
@@ -1337,6 +1337,10 @@ see the files COPYING3 and COPYING.RUNTI
 #define SWITCHABLE_TARGET 0
 #endif
 
+#ifndef PIE_DEFAULT
+#define PIE_DEFAULT 0
+#endif
+
 #endif /* GCC_INSN_FLAGS_H  */
 
 #endif  /* ! GCC_DEFAULTS_H */
