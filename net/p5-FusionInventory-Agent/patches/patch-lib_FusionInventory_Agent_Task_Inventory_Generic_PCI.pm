$NetBSD: patch-lib_FusionInventory_Agent_Task_Inventory_Generic_PCI.pm,v 1.1 2021/05/06 20:25:15 bouyer Exp $

accept pcictl as alternative to lspci

--- ./lib/FusionInventory/Agent/Task/Inventory/Generic/PCI.pm.orig	2021-05-06 18:34:38.856037719 +0200
+++ ./lib/FusionInventory/Agent/Task/Inventory/Generic/PCI.pm	2021-05-06 18:35:03.442742192 +0200
@@ -8,7 +8,7 @@
 use FusionInventory::Agent::Tools;
 
 sub isEnabled {
-    return canRun('lspci');
+    return canRun('lspci') || canRun('pcictl');
 }
 
 sub doInventory {}
