$NetBSD: patch-winpr_libwinpr_sysinfo_sysinfo.c,v 1.1 2019/09/15 12:55:14 nia Exp $

Support NetBSD.

--- winpr/libwinpr/sysinfo/sysinfo.c.orig	2018-11-20 10:43:51.000000000 +0000
+++ winpr/libwinpr/sysinfo/sysinfo.c
@@ -142,7 +142,7 @@ static DWORD GetNumberOfProcessors(void)
 		int mib[4];
 		size_t length = sizeof(numCPUs);
 		mib[0] = CTL_HW;
-#if defined(__FreeBSD__) || defined(__OpenBSD__)
+#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
 		mib[1] = HW_NCPU;
 #else
 		mib[1] = HW_AVAILCPU;
