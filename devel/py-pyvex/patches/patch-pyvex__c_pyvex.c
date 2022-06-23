$NetBSD: patch-pyvex__c_pyvex.c,v 1.1 2022/06/23 13:50:05 he Exp $

Initial attempt at doing powerpc as well.
Overlooked here?  The code has other mentions of the arch...

--- pyvex_c/pyvex.c.orig	2021-05-18 20:52:08.000000000 +0000
+++ pyvex_c/pyvex.c
@@ -172,6 +172,8 @@ int vex_init() {
 #elif __s390x__
 	vta.arch_host = VexArchS390X;
 	vai_host.hwcaps = VEX_HWCAPS_S390X_LDISP;
+#elif __powerpc__
+	vta.arch_host = VexArchPPC32;
 #else
 #error "Unsupported host arch"
 #endif
