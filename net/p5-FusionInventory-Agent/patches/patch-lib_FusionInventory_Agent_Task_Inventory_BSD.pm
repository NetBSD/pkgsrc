$NetBSD: patch-lib_FusionInventory_Agent_Task_Inventory_BSD.pm,v 1.1 2021/05/06 20:25:15 bouyer Exp $

Adjust for NetBSD's sysctl kern.boottime output

--- lib/FusionInventory/Agent/Task/Inventory/BSD.pm.orig	2021-05-05 00:17:48.974000555 +0200
+++ lib/FusionInventory/Agent/Task/Inventory/BSD.pm	2021-05-05 00:20:26.256041770 +0200
@@ -28,6 +28,12 @@
         command => "sysctl -n kern.boottime",
         pattern => qr/sec = (\d+)/
     );
+    if (! defined($boottime)) {
+        $boottime = getFirstMatch(
+            command => "sysctl -n kern.boottime",
+            pattern => qr/(\d+)/
+        );
+    }
 
     my $name = canRun('lsb_release') ?
         getFirstMatch(
