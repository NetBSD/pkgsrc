$NetBSD: patch-vendor_golang.org_x_sys_cpu_cpu__arm64.go,v 1.2 2020/06/09 11:32:43 nia Exp $

copypasta of devel/go-sys/patches/patch-cpu_cpu__arm64.go

--- vendor/golang.org/x/sys/cpu/cpu_arm64.go.orig	2020-06-02 09:59:11.000000000 +0000
+++ vendor/golang.org/x/sys/cpu/cpu_arm64.go
@@ -10,8 +10,12 @@ const cacheLineSize = 64
 
 func init() {
 	switch runtime.GOOS {
-	case "android", "darwin":
+	case "android", "darwin", "netbsd":
 		// Android and iOS don't seem to allow reading these registers.
+		// NetBSD:
+		// ID_AA64ISAR0_EL1 is a privileged register and cannot be read from EL0.
+		// It can be read via sysctl(3). Example for future implementers:
+		// https://nxr.netbsd.org/xref/src/usr.sbin/cpuctl/arch/aarch64.c
 		// Fake the minimal features expected by
 		// TestARM64minimalFeatures.
 		ARM64.HasASIMD = true
