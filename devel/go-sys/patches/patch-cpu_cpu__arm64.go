$NetBSD: patch-cpu_cpu__arm64.go,v 1.1 2020/05/01 20:57:44 tnn Exp $

Fix SIGILL on netbsd/arm64

--- cpu/cpu_arm64.go.orig	2020-02-02 16:47:22.000000000 +0000
+++ cpu/cpu_arm64.go
@@ -10,8 +10,13 @@ const cacheLineSize = 64
 
 func init() {
 	switch runtime.GOOS {
-	case "android", "darwin":
+	case "android", "darwin", "netbsd":
 		// Android and iOS don't seem to allow reading these registers.
+		// NetBSD:
+		// ID_AA64ISAR0_EL1 is a privileged register and cannot be read from EL0.
+		// It can be read via sysctl(3). Example for future implementers:
+		// https://nxr.netbsd.org/xref/src/usr.sbin/cpuctl/arch/aarch64.c
+		//
 		// Fake the minimal features expected by
 		// TestARM64minimalFeatures.
 		ARM64.HasASIMD = true
