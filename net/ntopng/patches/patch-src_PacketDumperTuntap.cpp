$NetBSD: patch-src_PacketDumperTuntap.cpp,v 1.3 2023/11/20 17:59:35 adam Exp $

Add NetBSD and SunOS support.

--- src/PacketDumperTuntap.cpp.orig	2023-11-02 14:11:55.000000000 +0000
+++ src/PacketDumperTuntap.cpp
@@ -133,7 +133,7 @@ int PacketDumperTuntap::openTap(
 
 /* ********************************************* */
 
-#ifdef __OpenBSD__
+#if defined(__NetBSD__) || defined(__OpenBSD__) || defined(__sun)
 #define OPENBSD_TAPDEVICE_SIZE 32
 int PacketDumperTuntap::openTap(
     char *dev, /* user-definable interface name, eg. edge0 */ int mtu) {
