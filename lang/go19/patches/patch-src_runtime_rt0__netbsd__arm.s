$NetBSD: patch-src_runtime_rt0__netbsd__arm.s,v 1.1 2018/07/08 17:59:07 bsiegert Exp $

--- src/runtime/rt0_netbsd_arm.s.orig	2017-02-16 19:12:24.000000000 +0000
+++ src/runtime/rt0_netbsd_arm.s
@@ -9,3 +9,8 @@ TEXT _rt0_arm_netbsd(SB),NOSPLIT,$-4
 	MOVW	$4(R13), R1		// argv
 	MOVM.DB.W [R0-R1], (R13)
 	B runtime·rt0_go(SB)
+
+TEXT main(SB),NOSPLIT,$-4
+	MOVM.DB.W [R0-R1], (R13)
+	MOVW	$runtime·rt0_go(SB), R4
+	B	(R4)
