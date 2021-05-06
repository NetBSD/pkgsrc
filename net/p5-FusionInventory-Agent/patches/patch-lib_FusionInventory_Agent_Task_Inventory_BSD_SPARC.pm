$NetBSD: patch-lib_FusionInventory_Agent_Task_Inventory_BSD_SPARC.pm,v 1.1 2021/05/06 20:25:15 bouyer Exp $

Use /var/run/dmesg.boot if present

--- lib/FusionInventory/Agent/Task/Inventory/BSD/SPARC.pm.orig	2021-05-04 23:09:07.913462371 +0200
+++ lib/FusionInventory/Agent/Task/Inventory/BSD/SPARC.pm	2021-05-04 23:09:59.586815307 +0200
@@ -57,9 +57,16 @@
     # cpu0: Sun Microsystems UltraSparc-I Processor (167.00 MHz CPU)
 
     my $cpu;
-    foreach my $line (getAllLines(command => 'dmesg')) {
-        if ($line=~ /^mainbus0 \(root\):\s*(.*)$/) { $bios->{SMODEL} = $1; }
-        if ($line =~ /^cpu[^:]*:\s*(.*)$/i)        { $cpu->{NAME}    = $1; }
+    if ( -r "/var/run/dmesg.boot") {
+	foreach my $line (getAllLines(file => '/var/run/dmesg.boot')) {
+            if ($line=~ /^mainbus0 \(root\):\s*(.*)$/) { $bios->{SMODEL} = $1; }
+            if ($line =~ /^cpu[^:]*:\s*(.*)$/i)        { $cpu->{NAME}    = $1; }
+        }
+    } else {
+        foreach my $line (getAllLines(command => 'dmesg')) {
+            if ($line=~ /^mainbus0 \(root\):\s*(.*)$/) { $bios->{SMODEL} = $1; }
+            if ($line =~ /^cpu[^:]*:\s*(.*)$/i)        { $cpu->{NAME}    = $1; }
+        }
     }
 
     $bios->{SMODEL} =~ s/SUNW,//;
