$NetBSD: patch-Source_Core_Core_MemTools.cpp,v 1.1 2019/01/01 17:19:58 nia Exp $

Support NetBSD.

--- Source/Core/Core/MemTools.cpp.orig	2016-06-24 08:09:07.000000000 +0000
+++ Source/Core/Core/MemTools.cpp
@@ -18,7 +18,7 @@
 #ifndef _M_GENERIC
 #include "Core/PowerPC/JitCommon/JitBase.h"
 #endif
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__NetBSD__)
 #include <signal.h>
 #endif
 #ifndef _WIN32
