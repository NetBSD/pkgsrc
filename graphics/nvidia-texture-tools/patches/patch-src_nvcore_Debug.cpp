$NetBSD: patch-src_nvcore_Debug.cpp,v 1.1 2016/09/18 17:08:20 kamil Exp $

Add NetBSD support.

--- src/nvcore/Debug.cpp.orig	2010-05-15 09:12:05.000000000 +0000
+++ src/nvcore/Debug.cpp
@@ -34,7 +34,7 @@
 #	endif
 #endif
 
-#if NV_OS_DARWIN
+#if NV_OS_DARWIN || NV_OS_NETBSD
 #	include <unistd.h>	// getpid
 #	include <sys/types.h>
 #	include <sys/sysctl.h>	// sysctl
@@ -133,7 +133,7 @@ namespace 
 
 #elif !NV_OS_WIN32 && defined(HAVE_SIGNAL_H) // NV_OS_LINUX || NV_OS_DARWIN
 
-#if defined(HAVE_EXECINFO_H) // NV_OS_LINUX
+#if defined(HAVE_EXECINFO_H) // NV_OS_LINUX || NV_OS_NETBSD
 
 	static bool nvHasStackTrace() {
 #if NV_OS_DARWIN
@@ -199,6 +199,17 @@ namespace 
 				return (void *) ucp->uc_mcontext->ss.eip;
 #			endif
 #		endif
+#	elif NV_OS_NETBSD
+#		if NV_CPU_X86_64
+			ucontext_t * ucp = (ucontext_t *)secret;
+			return (void *)ucp->uc_mcontext.__gregs[_REG_RIP];
+#		elif NV_CPU_X86
+			ucontext_t * ucp = (ucontext_t *)secret;
+			return (void *)ucp->uc_mcontext.__gregs[_REG_EIP];
+#		elif NV_CPU_PPC
+			ucontext_t * ucp = (ucontext_t *)secret;
+			return (void *)ucp->uc_mcontext.__gregs[_REG_PC];
+#		endif
 #	else
 #		if NV_CPU_X86_64
 			// #define REG_RIP REG_INDEX(rip) // seems to be 16
@@ -215,7 +226,7 @@ namespace 
 		
 		// How to obtain the instruction pointers in different platforms, from mlton's source code.
 		// http://mlton.org/
-		// OpenBSD && NetBSD
+		// OpenBSD
 		// ucp->sc_eip
 		// FreeBSD:
 		// ucp->uc_mcontext.mc_eip
@@ -534,4 +545,3 @@ void debug::disableSigHandler()
 	
 #endif
 }
-
