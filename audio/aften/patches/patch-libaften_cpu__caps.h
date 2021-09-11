$NetBSD: patch-libaften_cpu__caps.h,v 1.1 2021/09/11 23:44:49 nia Exp $

[PATCH] add fallback function for apply_simd_restrictions() on non-x86/ppc

git-svn-id: https://aften.svn.sourceforge.net/svnroot/aften@766 ef0d8562-5c19-0410-972e-841db63a069c

--- libaften/cpu_caps.h.orig	2007-08-11 16:13:25.000000000 +0000
+++ libaften/cpu_caps.h
@@ -26,6 +26,7 @@
 #include "ppc_cpu_caps.h"
 #else
 static inline void cpu_caps_detect(void){}
+static inline void apply_simd_restrictions(AftenSimdInstructions *simd_instructions){}
 #endif
 
 #endif /* CPU_CAPS_H */
