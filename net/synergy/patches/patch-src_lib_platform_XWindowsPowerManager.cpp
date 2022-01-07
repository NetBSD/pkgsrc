$NetBSD: patch-src_lib_platform_XWindowsPowerManager.cpp,v 1.1 2022/01/07 23:02:48 tnn Exp $

make dbus optional

--- src/lib/platform/XWindowsPowerManager.cpp.orig	2021-11-22 13:50:34.000000000 +0000
+++ src/lib/platform/XWindowsPowerManager.cpp
@@ -25,11 +25,13 @@ bool sleepInhibitCall(bool state, ArchSy
 {
     std::string error;
 
+#ifdef WITH_DBUS
     if (!ArchSystemUnix::DBusInhibitScreenCall(serviceID, state, error))
     {
         LOG((CLOG_DEBUG "DBus inhibit error %s", error.c_str()));
         return false;
     }
+#endif
 
     return true;
 }
