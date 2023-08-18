$NetBSD: patch-lib_irrlichtmt_source_Irrlicht_CIrrDeviceLinux.cpp,v 1.1 2023/08/18 10:51:52 pin Exp $

Use FreeBSD's support for NetBSD

--- lib/irrlichtmt/source/Irrlicht/CIrrDeviceLinux.cpp.orig	2023-03-05 20:45:09.000000000 +0000
+++ lib/irrlichtmt/source/Irrlicht/CIrrDeviceLinux.cpp
@@ -47,7 +47,7 @@
 #include <fcntl.h>
 #include <unistd.h>
 
-#ifdef __FreeBSD__
+#if defined(__NetBSD__) || defined(__FreeBSD__)
 #include <sys/joystick.h>
 #else
 
@@ -1578,7 +1578,7 @@ bool CIrrDeviceLinux::activateJoysticks(
 		if (-1 == info.fd)
 			continue;
 
-#ifdef __FreeBSD__
+#if defined(__NetBSD__) || defined(__FreeBSD__)
 		info.axes=2;
 		info.buttons=2;
 #else
@@ -1602,7 +1602,7 @@ bool CIrrDeviceLinux::activateJoysticks(
 		returnInfo.Axes = info.axes;
 		returnInfo.Buttons = info.buttons;
 
-#ifndef __FreeBSD__
+#if !defined(__NetBSD__) && !defined(__FreeBSD__)
 		char name[80];
 		ioctl( info.fd, JSIOCGNAME(80), name);
 		returnInfo.Name = name;
@@ -1637,7 +1637,7 @@ void CIrrDeviceLinux::pollJoysticks()
 	{
 		JoystickInfo & info =  ActiveJoysticks[j];
 
-#ifdef __FreeBSD__
+#if defined(__NetBSD__) || defined(__FreeBSD__)
 		struct joystick js;
 		if (read(info.fd, &js, sizeof(js)) == sizeof(js))
 		{
