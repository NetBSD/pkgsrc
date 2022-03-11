$NetBSD: patch-src_lib_arch_unix_ArchSystemUnix.cpp,v 1.2 2022/03/11 20:49:13 tnn Exp $

make dbus optional

--- src/lib/arch/unix/ArchSystemUnix.cpp.orig	2022-02-21 11:08:47.000000000 +0000
+++ src/lib/arch/unix/ArchSystemUnix.cpp
@@ -19,7 +19,7 @@
 #include "arch/unix/ArchSystemUnix.h"
 
 #include <sys/utsname.h>
-#ifndef __APPLE__
+#ifdef WITH_DBUS
 #include <QtDBus>
 #endif
 
@@ -82,7 +82,7 @@ ArchSystemUnix::getLibsUsed(void) const
     return "not implemented.\nuse lsof on shell";
 }
 
-#ifndef __APPLE__
+#ifdef WITH_DBUS
 bool
 ArchSystemUnix::DBusInhibitScreenCall(InhibitScreenServices serviceID, bool state, std::string& error)
 {
