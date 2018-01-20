$NetBSD: patch-src_runtime_os__netbsd.c,v 1.1 2018/01/20 16:55:25 christos Exp $

 * Use 'Real' pagesize from sysctl mib HW_PAGESIZE

 * Change HW_NCPU to NCPUONLINE for  'Real' number of available CPU

--- src/runtime/os_netbsd.c.orig	2015-09-23 04:37:37.000000000 +0000
+++ src/runtime/os_netbsd.c
@@ -5,6 +5,7 @@
 #include "runtime.h"
 #include "defs_GOOS_GOARCH.h"
 #include "os_GOOS.h"
+#include "arch_GOARCH.h"
 #include "signal_unix.h"
 #include "stack.h"
 #include "textflag.h"
@@ -35,7 +36,8 @@ extern int32 runtime·lwp_self(void);
 
 // From NetBSD's <sys/sysctl.h>
 #define	CTL_HW	6
-#define	HW_NCPU	3
+#define	HW_NCPUONLINE	16
+#define	HW_PAGESIZE	7
 
 static int32
 getncpu(void)
@@ -47,7 +49,7 @@ getncpu(void)
 
 	// Fetch hw.ncpu via sysctl.
 	mib[0] = CTL_HW;
-	mib[1] = HW_NCPU;
+	mib[1] = HW_NCPUONLINE;
 	nout = sizeof out;
 	out = 0;
 	ret = runtime·sysctl(mib, 2, (byte*)&out, &nout, nil, 0);
@@ -57,6 +59,23 @@ getncpu(void)
 		return 1;
 }
 
+static uintptr
+getphyspagesize(void)
+{
+	uint32 mib[2];
+	uintptr out, nout;
+	int32 ret;
+	mib[0] = CTL_HW;
+	mib[1] = HW_PAGESIZE;
+	nout = sizeof out;
+	out = 0;
+	ret = runtime·sysctl(mib, 2, (byte*)&out, &nout, nil, 0);
+	if(ret >= 0)
+		return out;
+	else
+		return PhysPageSize;
+}
+
 #pragma textflag NOSPLIT
 uintptr
 runtime·semacreate(void)
@@ -239,6 +258,7 @@ void
 runtime·osinit(void)
 {
 	runtime·ncpu = getncpu();
+	runtime·physpagesz = getphyspagesize();
 }
 
 #pragma textflag NOSPLIT
