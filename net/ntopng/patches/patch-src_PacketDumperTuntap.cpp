$NetBSD: patch-src_PacketDumperTuntap.cpp,v 1.2 2017/06/15 14:54:45 fhajny Exp $

Add NetBSD and SunOS support.

--- src/PacketDumperTuntap.cpp.orig	2016-06-27 19:31:18.000000000 +0000
+++ src/PacketDumperTuntap.cpp
@@ -127,7 +127,7 @@ int PacketDumperTuntap::openTap(char *de
 
 /* ********************************************* */
 
-#ifdef __OpenBSD__
+#if defined(__NetBSD__) || defined(__OpenBSD__) || defined(__sun)
 #define OPENBSD_TAPDEVICE_SIZE 32
 int PacketDumperTuntap::openTap(char *dev, /* user-definable interface name, eg. edge0 */ int mtu) {
   int i;
