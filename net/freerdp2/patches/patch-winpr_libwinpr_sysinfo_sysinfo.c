$NetBSD: patch-winpr_libwinpr_sysinfo_sysinfo.c,v 1.2 2021/05/02 08:26:49 jdolecek Exp $

Use _SC_NPROCESSORS_ONLN if available, remove OS-specific ifdef for it,
and also for HW_NCPU. Technically NetBSD would need to be added to the HW_NCPU
#idef, but no longer needed since it has _SC_NPROCESSORS_ONLN.

--- winpr/libwinpr/sysinfo/sysinfo.c.orig	2021-05-01 22:46:16.616257099 +0000
+++ winpr/libwinpr/sysinfo/sysinfo.c
@@ -132,7 +132,7 @@ static DWORD GetNumberOfProcessors(void)
 #if defined(ANDROID)
 	return android_getCpuCount();
 	/* TODO: iOS */
-#elif defined(__linux__) || defined(__sun) || defined(_AIX)
+#elif defined(_SC_NPROCESSORS_ONLN)
 	numCPUs = (DWORD)sysconf(_SC_NPROCESSORS_ONLN);
 #elif defined(__MACOSX__) || defined(__FreeBSD__) || defined(__NetBSD__) || \
     defined(__OpenBSD__) || defined(__DragonFly__)
@@ -140,7 +140,7 @@ static DWORD GetNumberOfProcessors(void)
 		int mib[4];
 		size_t length = sizeof(numCPUs);
 		mib[0] = CTL_HW;
-#if defined(__FreeBSD__) || defined(__OpenBSD__)
+#if defined(HW_NCPU)
 		mib[1] = HW_NCPU;
 #else
 		mib[1] = HW_AVAILCPU;
