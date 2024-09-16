$NetBSD: patch-irr_src_CIrrDeviceLinux.cpp,v 1.2 2024/09/16 14:29:04 ktnb Exp $

Use FreeBSD's support for NetBSD

--- irr/src/CIrrDeviceLinux.cpp.orig	2024-09-16 13:40:09.623642575 +0000
+++ irr/src/CIrrDeviceLinux.cpp
@@ -28,6 +28,7 @@
 #include "IFileSystem.h"
 #include <X11/XKBlib.h>
 #include <X11/Xatom.h>
+#include <unistd.h>
 
 #if defined(_IRR_LINUX_X11_XINPUT2_)
 #include <X11/extensions/XInput2.h>
@@ -52,7 +53,7 @@
 #if defined _IRR_COMPILE_WITH_JOYSTICK_EVENTS_
 #include <fcntl.h>
 
-#ifdef __FreeBSD__
+#if defined(__NetBSD__) || defined(__FreeBSD__)
 #include <sys/joystick.h>
 #else
 
@@ -1580,7 +1581,7 @@ bool CIrrDeviceLinux::activateJoysticks(
 		if (-1 == info.fd)
 			continue;
 
-#ifdef __FreeBSD__
+#if defined(__NetBSD__) || defined(__FreeBSD__)
 		info.axes = 2;
 		info.buttons = 2;
 #else
@@ -1604,7 +1605,7 @@ bool CIrrDeviceLinux::activateJoysticks(
 		returnInfo.Axes = info.axes;
 		returnInfo.Buttons = info.buttons;
 
-#ifndef __FreeBSD__
+#if !defined(__NetBSD__) && !defined(__FreeBSD__)
 		char name[80];
 		ioctl(info.fd, JSIOCGNAME(80), name);
 		returnInfo.Name = name;
@@ -1636,7 +1637,7 @@ void CIrrDeviceLinux::pollJoysticks()
 	for (u32 j = 0; j < ActiveJoysticks.size(); ++j) {
 		JoystickInfo &info = ActiveJoysticks[j];
 
-#ifdef __FreeBSD__
+#if defined(__NetBSD__) || defined(__FreeBSD__)
 		struct joystick js;
 		if (read(info.fd, &js, sizeof(js)) == sizeof(js)) {
 			info.persistentData.JoystickEvent.ButtonStates = js.b1 | (js.b2 << 1); /* should be a two-bit field */
