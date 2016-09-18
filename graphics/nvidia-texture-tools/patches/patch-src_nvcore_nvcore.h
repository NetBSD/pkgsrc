$NetBSD: patch-src_nvcore_nvcore.h,v 1.1 2016/09/18 17:08:20 kamil Exp $

Add NetBSD support.

--- src/nvcore/nvcore.h.orig	2010-05-15 09:12:05.000000000 +0000
+++ src/nvcore/nvcore.h
@@ -43,6 +43,9 @@
 #elif defined POSH_OS_MINGW
 #	define NV_OS_MINGW 1
 #	define NV_OS_WIN32 1
+#elif defined POSH_OS_NETBSD
+#	define NV_OS_NETBSD 1
+#	define NV_OS_UNIX 1
 #elif defined POSH_OS_OSX
 #	define NV_OS_DARWIN 1
 #	define NV_OS_UNIX 1
@@ -160,6 +163,8 @@
 #		include "DefsGnucLinux.h"
 #	elif NV_OS_DARWIN
 #		include "DefsGnucDarwin.h"
+#	elif NV_OS_NETBSD
+#		include "DefsGnucNetBSD.h"
 #	elif NV_OS_MINGW
 #		include "DefsGnucWin32.h"
 #	elif NV_OS_CYGWIN
