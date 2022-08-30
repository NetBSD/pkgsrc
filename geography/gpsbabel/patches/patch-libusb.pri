$NetBSD: patch-libusb.pri,v 1.1 2022/08/30 23:47:05 gdt Exp $

Add NetBSD as a platform where libusb can be found by pkgconfig.  (One
wonders why it isn't allowed on any platform, since it presumably
fails if libusb is requested but not found.)

--- libusb.pri.orig	2022-01-19 21:08:42.000000000 +0000
+++ libusb.pri
@@ -1,4 +1,4 @@
-macx|linux|openbsd {
+macx|linux|netbsd|openbsd {
   !defined(WITH_LIBUSB, var) {
     macx: WITH_LIBUSB = included
     linux|openbsd: WITH_LIBUSB = system
