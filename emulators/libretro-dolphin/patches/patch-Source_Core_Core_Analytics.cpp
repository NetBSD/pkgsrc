$NetBSD: patch-Source_Core_Core_Analytics.cpp,v 1.1 2018/10/15 17:20:21 nia Exp $

Support NetBSD.

--- Source/Core/Core/Analytics.cpp.orig	2018-08-27 13:59:39.000000000 +0000
+++ Source/Core/Core/Analytics.cpp
@@ -173,6 +173,8 @@ void DolphinAnalytics::MakeBaseBuilder()
   builder.AddData("os-type", "linux");
 #elif defined(__FreeBSD__)
   builder.AddData("os-type", "freebsd");
+#elif defined(__NetBSD__)
+  builder.AddData("os-type", "netbsd");
 #else
   builder.AddData("os-type", "unknown");
 #endif
