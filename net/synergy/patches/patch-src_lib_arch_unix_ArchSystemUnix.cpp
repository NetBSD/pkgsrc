$NetBSD: patch-src_lib_arch_unix_ArchSystemUnix.cpp,v 1.1 2022/01/07 23:02:48 tnn Exp $

make dbus optional

--- src/lib/arch/unix/ArchSystemUnix.cpp.orig	2021-11-22 13:50:34.000000000 +0000
+++ src/lib/arch/unix/ArchSystemUnix.cpp
@@ -23,7 +23,7 @@
 #include <array>
 #include <memory>
 #include <string>
-#ifndef __APPLE__
+#ifdef WITH_DBUS
 #include <QtDBus>
 #endif
 
@@ -104,7 +104,7 @@ ArchSystemUnix::runCommand(const std::st
     return result;
 }
 
-#ifndef __APPLE__
+#ifdef WITH_DBUS
 bool
 ArchSystemUnix::DBusInhibitScreenCall(InhibitScreenServices serviceID, bool state, std::string& error)
 {
