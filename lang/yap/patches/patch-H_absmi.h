$NetBSD: patch-H_absmi.h,v 1.1 2021/12/29 03:14:35 dholland Exp $

Fix (by blunt hammer) build failure on hppa, alpha, mips, and ppc.
(Would be better to fix the offending code. Maybe sometime.)

--- H/absmi.h~	2012-12-14 09:03:05.000000000 +0000
+++ H/absmi.h
@@ -142,6 +142,9 @@ register struct yami* P1REG asm ("bp"); 
 
 #endif /* __GNUC__ */
 
+/* The USE_PREFETCH code doesn't compile. Shut it off forcibly. */
+#undef USE_PREFETCH
+
 #include "Yap.h"
 #include "clause.h"
 #include "eval.h"
