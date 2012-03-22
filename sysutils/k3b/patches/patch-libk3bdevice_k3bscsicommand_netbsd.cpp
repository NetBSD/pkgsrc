$NetBSD: patch-libk3bdevice_k3bscsicommand_netbsd.cpp,v 1.1 2012/03/22 06:39:01 markd Exp $

--- libk3bdevice/k3bscsicommand_netbsd.cpp.orig	2009-04-04 04:27:24.000000000 +1300
+++ libk3bdevice/k3bscsicommand_netbsd.cpp
@@ -53,7 +53,7 @@ int K3b::Device::ScsiCommand::transport(
                                          size_t len )
 {
     bool needToClose = false;
-    int deviceHandler = -1;
+    int deviceHandle = -1;
     if( m_device ) {
         m_device->usageLock();
         if( !m_device->isOpen() ) {
