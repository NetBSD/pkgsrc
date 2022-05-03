$NetBSD: patch-Swiften_Network_PlatformNATTraversalWorker.cpp,v 1.1 2022/05/03 20:03:31 nia Exp $

Support newer Qt versions. via Arch Linux.

--- Swiften/Network/PlatformNATTraversalWorker.cpp.orig	2018-04-06 10:06:46.000000000 +0000
+++ Swiften/Network/PlatformNATTraversalWorker.cpp
@@ -157,7 +157,7 @@ NATTraversalInterface* PlatformNATTraver
         miniUPnPInterface = new MiniUPnPInterface();
         miniUPnPSupported = miniUPnPInterface->isAvailable();
     }
-    SWIFT_LOG(debug) << "UPnP NAT traversal supported: " << miniUPnPSupported << std::endl;
+    SWIFT_LOG(debug) << "UPnP NAT traversal supported: " << static_cast<bool>(miniUPnPSupported) << std::endl;
     if (miniUPnPSupported) {
         return miniUPnPInterface;
     }
@@ -168,7 +168,7 @@ NATTraversalInterface* PlatformNATTraver
         natPMPInterface = new NATPMPInterface();
         natPMPSupported = natPMPInterface->isAvailable();
     }
-    SWIFT_LOG(debug) << "NAT-PMP NAT traversal supported: " << natPMPSupported << std::endl;
+    SWIFT_LOG(debug) << "NAT-PMP NAT traversal supported: " << static_cast<bool>(natPMPSupported) << std::endl;
     if (natPMPSupported) {
         return natPMPInterface;
     }
