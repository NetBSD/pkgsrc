$NetBSD: patch-libk3bdevice_k3bdevice.cpp,v 1.1 2012/03/22 06:39:01 markd Exp $

--- libk3bdevice/k3bdevice.cpp.orig	2009-05-07 19:08:16.000000000 +1200
+++ libk3bdevice/k3bdevice.cpp
@@ -35,6 +35,7 @@
 #include <Solid/OpticalDrive>
 #include <Solid/Block>
 #include <Solid/StorageAccess>
+#include <Solid/GenericInterface>
 
 #include <sys/types.h>
 #include <sys/ioctl.h>
@@ -242,9 +243,14 @@ K3b::Device::Device::Handle K3b::Device:
 
 K3b::Device::Device::Device( const Solid::Device& dev )
 {
+    const Solid::GenericInterface *gi = dev.as<Solid::GenericInterface>();
+
     d = new Private;
     d->solidDevice = dev;
-    d->blockDevice = dev.as<Solid::Block>()->device();
+    if (gi->propertyExists("block.netbsd.raw_device"))
+        d->blockDevice = gi->property("block.netbsd.raw_device").toString();
+    else
+        d->blockDevice = dev.as<Solid::Block>()->device();
     d->writeModes = 0;
     d->maxWriteSpeed = 0;
     d->maxReadSpeed = 0;
