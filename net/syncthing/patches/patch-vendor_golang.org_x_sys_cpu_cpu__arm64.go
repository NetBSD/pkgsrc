$NetBSD: patch-vendor_golang.org_x_sys_cpu_cpu__arm64.go,v 1.1 2020/05/01 21:09:03 tnn Exp $

copypasta of devel/go-sys/patches/patch-cpu_cpu__arm64.go

--- vendor/golang.org/x/sys/cpu/cpu_arm64.go.orig	2020-04-08 07:13:30.000000000 +0000
+++ vendor/golang.org/x/sys/cpu/cpu_arm64.go
@@ -10,8 +10,14 @@ const cacheLineSize = 64
 
 func init() {
 	switch runtime.GOOS {
-	case "darwin":
+	case "darwin", "netbsd":
 		// iOS does not seem to allow reading these registers
+		// NetBSD:
+		// ID_AA64ISAR0_EL1 is a privileged register and cannot be read from EL0.
+		// It can be read via sysctl(3). Example for future implementers:
+		// https://nxr.netbsd.org/xref/src/usr.sbin/cpuctl/arch/aarch64.c
+		ARM64.HasASIMD = true
+		ARM64.HasFP = true
 	case "android", "linux":
 		doinit()
 	default:
