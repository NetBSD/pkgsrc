$NetBSD: patch-libk3bdevice_k3bdevice.cpp,v 1.2 2014/11/15 03:35:26 markd Exp $

--- libk3bdevice/k3bdevice.cpp.orig	2014-11-04 18:37:31.000000000 +0000
+++ libk3bdevice/k3bdevice.cpp
@@ -35,7 +35,7 @@
 #include <Solid/OpticalDrive>
 #include <Solid/Block>
 #include <Solid/StorageAccess>
-#ifdef __NETBSD__
+#ifdef Q_OS_NETBSD
 #include <Solid/GenericInterface>
 #endif
 
@@ -245,12 +245,12 @@ K3b::Device::Device::Handle K3b::Device:
 
 K3b::Device::Device::Device( const Solid::Device& dev )
 {
-#ifdef __NETBSD__
-    const Solid::GenericInterace *gi = dev.as<Solid::GenericInterface>();
+#ifdef Q_OS_NETBSD
+    const Solid::GenericInterface *gi = dev.as<Solid::GenericInterface>();
 #endif
     d = new Private;
     d->solidDevice = dev;
-#ifndef __NETBSD__
+#ifndef Q_OS_NETBSD
     d->blockDevice = dev.as<Solid::Block>()->device();
 #else
     if (gi->propertyExists("block.netbsd.raw_device"))
