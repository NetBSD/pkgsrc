$NetBSD: patch-lib_FusionInventory_Agent_Task_Inventory_BSD_Alpha.pm,v 1.1 2021/05/06 20:25:15 bouyer Exp $

Use /var/run/dmesg.boot if present

--- lib/FusionInventory/Agent/Task/Inventory/BSD/Alpha.pm.orig	2021-05-04 23:00:51.263555904 +0200
+++ lib/FusionInventory/Agent/Task/Inventory/BSD/Alpha.pm	2021-05-04 22:57:35.095417352 +0200
@@ -42,9 +42,16 @@
     # CPU: EV45 (21064A) major=6 minor=2
 
     my $cpu;
-    foreach my $line (getAllLines(command => 'dmesg')) {
-        if ($line =~ /$bios->{SMODEL},\s*(\S+)\s*MHz/) { $cpu->{SPEED} = $1; }
-        if ($line =~ /^cpu[^:]*:\s*(.*)$/i)            { $cpu->{NAME} = $1;  }
+    if ( -r "/var/run/dmesg.boot") {
+	foreach my $line (getAllLines(file => '/var/run/dmesg.boot')) {
+            if ($line =~ /$bios->{SMODEL},\s*(\S+)\s*MHz/) { $cpu->{SPEED} = $1; }
+            if ($line =~ /^cpu[^:]*:\s*(.*)$/i)            { $cpu->{NAME} = $1;  }
+	}
+    } else {
+        foreach my $line (getAllLines(command => 'dmesg')) {
+            if ($line =~ /$bios->{SMODEL},\s*(\S+)\s*MHz/) { $cpu->{SPEED} = $1; }
+            if ($line =~ /^cpu[^:]*:\s*(.*)$/i)            { $cpu->{NAME} = $1;  }
+        }
     }
 
     $inventory->setBios($bios);
