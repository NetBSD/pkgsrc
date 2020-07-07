$NetBSD: patch-bsd_kernel.cc,v 1.3 2020/07/07 19:13:18 bsiegert Exp $

Don't fail for unprivileged users.

https://github.com/hills/xosview/pull/15

--- bsd/kernel.cc.orig	2020-02-22 19:33:08.000000000 +0000
+++ bsd/kernel.cc
@@ -219,8 +219,10 @@ OpenKDIfNeeded() {
 	 *  that kernel file.  Otherwise, use the default kernel, by
 	 *  specifying NULL.  */
 	if ((kd = kvm_openfiles((kernelFileName[0] ? kernelFileName : NULL),
-		                    NULL, NULL, O_RDONLY, errstring)) == NULL)
-		err(EX_OSFILE, "OpenKDIfNeeded(): %s", errstring);
+		                    NULL, NULL, O_RDONLY, errstring)) == NULL) {
+		warn("OpenKDIfNeeded(): %s", errstring);
+		return;
+	}
 
 	// Parenthetical note:  FreeBSD kvm_openfiles() uses getbootfile() to get
 	// the correct kernel file if the 1st arg is NULL.  As far as I can see,
@@ -276,7 +278,7 @@ BSDGetCPUSpeed() {
 	size = sizeof(speed);
 #if defined(XOSVIEW_NETBSD)
 	if ( sysctlbyname("machdep.tsc_freq", &speed, &size, NULL, 0) < 0 )
-		err(EX_OSERR, "sysctl machdep.tsc_freq failed");
+		return 0;
 #else  /* XOSVIEW_DFBSD */
 	if ( sysctlbyname("hw.tsc_frequency", &speed, &size, NULL, 0) < 0 )
 		err(EX_OSERR, "sysctl hw.tsc_frequency failed");
