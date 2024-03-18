$NetBSD: patch-libs_vst3_pluginterfaces_base_fplatform.h,v 1.1 2024/03/18 15:36:15 ryoon Exp $

--- libs/vst3/pluginterfaces/base/fplatform.h.orig	2024-02-04 02:22:43.806501710 +0000
+++ libs/vst3/pluginterfaces/base/fplatform.h
@@ -86,7 +86,7 @@
 //-----------------------------------------------------------------------------
 // LINUX
 //-----------------------------------------------------------------------------
-#elif __gnu_linux__ || __linux__
+#elif __gnu_linux__ || __linux__ || __FreeBSD__ || __NetBSD__ || __OpenBSD__
 	#define SMTG_OS_LINUX	1
 	#define SMTG_OS_MACOS	0
 	#define SMTG_OS_WINDOWS	0
