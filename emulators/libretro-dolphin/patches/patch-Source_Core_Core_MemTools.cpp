$NetBSD: patch-Source_Core_Core_MemTools.cpp,v 1.1 2018/10/15 17:20:21 nia Exp $

Support NetBSD.

--- Source/Core/Core/MemTools.cpp.orig	2018-08-27 13:59:39.000000000 +0000
+++ Source/Core/Core/MemTools.cpp
@@ -17,7 +17,7 @@
 #include "Core/MachineContext.h"
 #include "Core/PowerPC/JitInterface.h"
 
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__NetBSD__)
 #include <signal.h>
 #endif
 #ifndef _WIN32
