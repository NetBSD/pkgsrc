$NetBSD: patch-libk3bdevice_k3bdevicemanager.cpp,v 1.2 2014/11/15 03:35:26 markd Exp $

--- libk3bdevice/k3bdevicemanager.cpp.orig	2014-11-04 18:37:31.000000000 +0000
+++ libk3bdevice/k3bdevicemanager.cpp
@@ -39,7 +39,7 @@
 #include <Solid/OpticalDrive>
 #include <Solid/Block>
 #include <Solid/Device>
-#ifdef __NETBSD__
+#ifdef Q_OS_NETBSD
 #include <Solid/GenericInterface>
 #endif
 
@@ -359,10 +359,10 @@ bool K3b::Device::DeviceManager::saveCon
 K3b::Device::Device* K3b::Device::DeviceManager::addDevice( const Solid::Device& solidDevice )
 {
     if( const Solid::Block* blockDevice = solidDevice.as<Solid::Block>() ) {
-#ifndef __NETBSD__
+#ifndef Q_OS_NETBSD
         if( !findDevice( blockDevice->device() ) )
 #else
-        if( !findDevice( solidDevice.as<Solid::GenericInterface>()->propertyExists("block.netbsd.raw_device") ? solidDevice.as<Solid::GenericInterface>()->property("block.netbsd.raw_device").toString() : blockDevice->device() ) );
+        if( !findDevice( solidDevice.as<Solid::GenericInterface>()->propertyExists("block.netbsd.raw_device") ? solidDevice.as<Solid::GenericInterface>()->property("block.netbsd.raw_device").toString() : blockDevice->device() ) )
 #endif
             return addDevice( new K3b::Device::Device( solidDevice ) );
         else
