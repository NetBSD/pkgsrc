$NetBSD: patch-lib_irrlichtmt_source_Irrlicht_CIrrDeviceLinux.cpp,v 1.2 2024/01/02 14:18:07 gdt Exp $

Use FreeBSD's support for NetBSD

--- lib/irrlichtmt/source/Irrlicht/CIrrDeviceLinux.cpp.orig	2023-10-27 15:48:29.000000000 +0000
+++ lib/irrlichtmt/source/Irrlicht/CIrrDeviceLinux.cpp
@@ -28,6 +28,7 @@
 #include "IFileSystem.h"
 #include <X11/XKBlib.h>
 #include <X11/Xatom.h>
+#include <unistd.h>
 
 #if defined(_IRR_LINUX_X11_XINPUT2_)
 #include <X11/extensions/XInput2.h>
@@ -47,9 +48,8 @@
 
 #if defined _IRR_COMPILE_WITH_JOYSTICK_EVENTS_
 #include <fcntl.h>
-#include <unistd.h>
 
-#ifdef __FreeBSD__
+#if defined(__NetBSD__) || defined(__FreeBSD__)
 #include <sys/joystick.h>
 #else
 
@@ -1690,7 +1690,7 @@ bool CIrrDeviceLinux::activateJoysticks(
 		if (-1 == info.fd)
 			continue;
 
-#ifdef __FreeBSD__
+#if defined(__NetBSD__) || defined(__FreeBSD__)
 		info.axes=2;
 		info.buttons=2;
 #else
@@ -1714,7 +1714,7 @@ bool CIrrDeviceLinux::activateJoysticks(
 		returnInfo.Axes = info.axes;
 		returnInfo.Buttons = info.buttons;
 
-#ifndef __FreeBSD__
+#if !defined(__NetBSD__) && !defined(__FreeBSD__)
 		char name[80];
 		ioctl( info.fd, JSIOCGNAME(80), name);
 		returnInfo.Name = name;
@@ -1749,7 +1749,7 @@ void CIrrDeviceLinux::pollJoysticks()
 	{
 		JoystickInfo & info =  ActiveJoysticks[j];
 
-#ifdef __FreeBSD__
+#if defined(__NetBSD__) || defined(__FreeBSD__)
 		struct joystick js;
 		if (read(info.fd, &js, sizeof(js)) == sizeof(js))
 		{
