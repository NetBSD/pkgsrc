$NetBSD: patch-libk3bdevice_k3bdevicemanager.cpp,v 1.1 2012/03/22 06:39:01 markd Exp $

--- libk3bdevice/k3bdevicemanager.cpp.orig	2011-01-15 20:47:29.000000000 +0000
+++ libk3bdevice/k3bdevicemanager.cpp
@@ -39,6 +39,7 @@
 #include <Solid/OpticalDrive>
 #include <Solid/Block>
 #include <Solid/Device>
+#include <Solid/GenericInterface>
 
 #include <iostream>
 #include <limits.h>
@@ -356,7 +357,7 @@ bool K3b::Device::DeviceManager::saveCon
 K3b::Device::Device* K3b::Device::DeviceManager::addDevice( const Solid::Device& solidDevice )
 {
     if( const Solid::Block* blockDevice = solidDevice.as<Solid::Block>() ) {
-        if( !findDevice( blockDevice->device() ) )
+        if( !findDevice( solidDevice.as<Solid::GenericInterface>()->propertyExists("block.netbsd.raw_device") ? solidDevice.as<Solid::GenericInterface>()->property("block.netbsd.raw_device").toString() : blockDevice->device() ) )
             return addDevice( new K3b::Device::Device( solidDevice ) );
         else
             kDebug() << "(K3b::Device::DeviceManager) dev " << blockDevice->device()  << " already found";
