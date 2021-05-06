$NetBSD: patch-lib_FusionInventory_Agent_Task_Inventory_BSD_MIPS.pm,v 1.1 2021/05/06 20:25:15 bouyer Exp $

Use /var/run/dmesg.boot if present

--- lib/FusionInventory/Agent/Task/Inventory/BSD/MIPS.pm.orig	2021-05-04 23:07:03.767869134 +0200
+++ lib/FusionInventory/Agent/Task/Inventory/BSD/MIPS.pm	2021-05-04 23:08:31.241450459 +0200
@@ -48,10 +48,18 @@
     # cpu0: cache L1-I 32KB D 32KB 2 way, L2 512KB direct
 
     my $cpu;
-    foreach my $line (getAllLines(command => 'dmesg')) {
-        if ($line =~ /$bios->{SMODEL}\s*\[\S*\s*(\S*)\]/) { $bios->{SSN} = $1; }
-        if ($line =~ /cpu0 at mainbus0:\s*(.*)$/)         { $cpu->{NAME} = $1; }
-        if ($line =~ /CPU\s*.*\D(\d+)\s*MHz/)             { $cpu->{SPEED} = $1;  }
+    if ( -r "/var/run/dmesg.boot") {
+	foreach my $line (getAllLines(file => '/var/run/dmesg.boot')) {
+            if ($line =~ /$bios->{SMODEL}\s*\[\S*\s*(\S*)\]/) { $bios->{SSN} = $1; }
+            if ($line =~ /cpu0 at mainbus0:\s*(.*)$/)         { $cpu->{NAME} = $1; }
+            if ($line =~ /CPU\s*.*\D(\d+)\s*MHz/)             { $cpu->{SPEED} = $1;  }
+        }
+    } else {
+	foreach my $line (getAllLines(command => 'dmesg')) {
+            if ($line =~ /$bios->{SMODEL}\s*\[\S*\s*(\S*)\]/) { $bios->{SSN} = $1; }
+            if ($line =~ /cpu0 at mainbus0:\s*(.*)$/)         { $cpu->{NAME} = $1; }
+            if ($line =~ /CPU\s*.*\D(\d+)\s*MHz/)             { $cpu->{SPEED} = $1;  }
+        }
     }
 
     $inventory->setBios($bios);
