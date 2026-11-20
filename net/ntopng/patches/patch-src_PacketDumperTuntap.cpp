$NetBSD: patch-src_PacketDumperTuntap.cpp,v 1.4 2026/11/20 13:12:04 adam Exp $

Add NetBSD and SunOS support.

--- src/PacketDumperTuntap.cpp.orig	2026-09-22 07:53:34.000000000 +0000
+++ src/PacketDumperTuntap.cpp
@@ -136,7 +136,7 @@ int PacketDumperTuntap::openTap(
 
 /* ********************************************* */
 
-#ifdef __OpenBSD__
+#if defined(__NetBSD__) || defined(__OpenBSD__) || defined(__sun)
 #define OPENBSD_TAPDEVICE_SIZE 32
 int PacketDumperTuntap::openTap(
     char* dev, /* user-definable interface name, eg. edge0 */ int mtu) {
