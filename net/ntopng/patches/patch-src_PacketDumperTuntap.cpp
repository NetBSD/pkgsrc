$NetBSD: patch-src_PacketDumperTuntap.cpp,v 1.1 2016/04/08 16:59:07 adam Exp $

Add NetBSD support.

--- src/PacketDumperTuntap.cpp.orig	2016-04-04 12:59:52.000000000 +0000
+++ src/PacketDumperTuntap.cpp
@@ -127,7 +127,7 @@ int PacketDumperTuntap::openTap(char *de
 
 /* ********************************************* */
 
-#ifdef __OpenBSD__
+#if defined(__NetBSD__) || defined(__OpenBSD__)
 #define OPENBSD_TAPDEVICE_SIZE 32
 int PacketDumperTuntap::openTap(char *dev, /* user-definable interface name, eg. edge0 */ int mtu) {
   int i;
