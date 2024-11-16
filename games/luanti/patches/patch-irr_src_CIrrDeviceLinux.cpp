$NetBSD: patch-irr_src_CIrrDeviceLinux.cpp,v 1.1 2024/11/16 01:57:06 ktnb Exp $

Use FreeBSD's support for NetBSD

--- irr/src/CIrrDeviceLinux.cpp.orig	2024-11-12 15:24:41.476828138 +0000
+++ irr/src/CIrrDeviceLinux.cpp
@@ -29,6 +29,7 @@
 #include "IVideoDriver.h"
 #include <X11/XKBlib.h>
 #include <X11/Xatom.h>
+#include <unistd.h>
 
 #if defined(_IRR_LINUX_X11_XINPUT2_)
 #include <X11/extensions/XInput2.h>
@@ -53,7 +54,7 @@
 #if defined _IRR_COMPILE_WITH_JOYSTICK_EVENTS_
 #include <fcntl.h>
 
-#ifdef __FreeBSD__
+#if defined(__NetBSD__) || defined(__FreeBSD__)
 #include <sys/joystick.h>
 #else
 
@@ -1572,7 +1573,7 @@ bool CIrrDeviceLinux::activateJoysticks(
 		if (-1 == info.fd)
 			continue;
 
-#ifdef __FreeBSD__
+#if defined(__NetBSD__) || defined(__FreeBSD__)
 		info.axes = 2;
 		info.buttons = 2;
 #else
@@ -1595,7 +1596,7 @@ bool CIrrDeviceLinux::activateJoysticks(
 		returnInfo.Axes = info.axes;
 		returnInfo.Buttons = info.buttons;
 
-#ifndef __FreeBSD__
+#if !defined(__NetBSD__) && !defined(__FreeBSD__)
 		char name[80];
 		ioctl(info.fd, JSIOCGNAME(80), name);
 		returnInfo.Name = name;
@@ -1627,7 +1628,7 @@ void CIrrDeviceLinux::pollJoysticks()
 	for (u32 j = 0; j < ActiveJoysticks.size(); ++j) {
 		JoystickInfo &info = ActiveJoysticks[j];
 
-#ifdef __FreeBSD__
+#if defined(__NetBSD__) || defined(__FreeBSD__)
 		struct joystick js;
 		if (read(info.fd, &js, sizeof(js)) == sizeof(js)) {
 			info.persistentData.JoystickEvent.ButtonStates = js.b1 | (js.b2 << 1); /* should be a two-bit field */
