$NetBSD: patch-lib_FusionInventory_Agent_Tools_Generic.pm,v 1.2 2021/05/07 18:27:20 bouyer Exp $

accept pcictl as alternative to lspci
Bring in upstream patch for better CPU report

--- lib/FusionInventory/Agent/Tools/Generic.pm.orig	2020-11-09 14:49:31.000000000 +0100
+++ lib/FusionInventory/Agent/Tools/Generic.pm	2021-05-07 20:08:32.214113753 +0200
@@ -126,10 +126,12 @@
             MANUFACTURER => $manufacturer
         };
         $cpu->{NAME} =
-            ($cpu->{MANUFACTURER} =~ /Intel/ ? $info->{'Family'} : undef) ||
             $info->{'Version'}                                     ||
+	    $info->{'Family'}					   ||
             $info->{'Processor Family'}                            ||
             $info->{'Processor Version'};
+	# Cleanup cpu NAME
+	$cpu->{NAME} =~ s/\((R|TM)\)//gi if $cpu->{NAME};
 
        if ($cpu->{ID}) {
 
@@ -217,52 +219,103 @@
 }
 
 sub getPCIDevices {
-    my (%params) = (
-        command => 'lspci -v -nn',
-        @_
-    );
-    my $handle = getFileHandle(%params);
-
-    my (@controllers, $controller);
-
-    while (my $line = <$handle>) {
-        chomp $line;
-
-        if ($line =~ /^
-            (\S+) \s                     # slot
-            ([^[]+) \s                   # name
-            \[([a-f\d]+)\]: \s           # class
-            (\S.+) \s                   # manufacturer
-            \[([a-f\d]+:[a-f\d]+)\]      # id
-            (?:\s \(rev \s (\d+)\))?     # optional version
-            /x) {
-
-            $controller = {
-                PCISLOT      => $1,
-                NAME         => $2,
-                PCICLASS     => $3,
-                MANUFACTURER => $4,
-                PCIID        => $5,
-                REV          => $6
-            };
-            next;
-        }
-
-        next unless defined $controller;
-
-        if ($line =~ /^$/) {
-            push(@controllers, $controller);
-            undef $controller;
-        } elsif ($line =~ /^\tKernel driver in use: (\w+)/) {
-            $controller->{DRIVER} = $1;
-        } elsif ($line =~ /^\tSubsystem: ?.* \[?([a-f\d]{4}:[a-f\d]{4})\]?/) {
-            $controller->{PCISUBSYSTEMID} = $1;
+    if (canRun('lspci')) {
+        my (%params) = (
+            command => 'lspci -v -nn',
+            @_
+        );
+        my $handle = getFileHandle(%params);
+    
+        my (@controllers, $controller);
+    
+        while (my $line = <$handle>) {
+            chomp $line;
+    
+            if ($line =~ /^
+                (\S+) \s                     # slot
+                ([^[]+) \s                   # name
+                \[([a-f\d]+)\]: \s           # class
+                (\S.+) \s                   # manufacturer
+                \[([a-f\d]+:[a-f\d]+)\]      # id
+                (?:\s \(rev \s (\d+)\))?     # optional version
+                /x) {
+    
+                $controller = {
+                    PCISLOT      => $1,
+                    NAME         => $2,
+                    PCICLASS     => $3,
+                    MANUFACTURER => $4,
+                    PCIID        => $5,
+                    REV          => $6
+                };
+                next;
+            }
+    
+            next unless defined $controller;
+    
+            if ($line =~ /^$/) {
+                push(@controllers, $controller);
+                undef $controller;
+            } elsif ($line =~ /^\tKernel driver in use: (\w+)/) {
+                $controller->{DRIVER} = $1;
+            } elsif ($line =~ /^\tSubsystem: ?.* \[?([a-f\d]{4}:[a-f\d]{4})\]?/) {
+                $controller->{PCISUBSYSTEMID} = $1;
+            }
         }
+    
+        close $handle;
+    
+        return @controllers;
     }
 
-    close $handle;
-
-    return @controllers;
+    if (canRun('pcictl')) {
+        my (%params) = (
+            command => 'pcictl pci0 list -N',
+            @_
+        );
+        my $handle = getFileHandle(%params);
+    
+        my (@controllers, $controller);
+    
+        while (my $line = <$handle>) {
+            chomp $line;
+
+	    if ($line =~ /^(\S+): ([^\(]+) \((.+), revision ([^\)]+)\)(?: \[(\S+)\])?/) {
+                $controller = {
+                    PCISLOT      => $1,
+                    NAME         => $3,
+                    MANUFACTURER => $2,
+                    REV          => $4,
+                    DRIVER       => $5
+                };
+                push(@controllers, $controller);
+                undef $controller;
+	    }
+	}
+        close $handle;
+        (%params) = (
+            command => 'pcictl pci0 list -n',
+            @_
+        );
+        $handle = getFileHandle(%params);
+    
+        while (my $line = <$handle>) {
+            chomp $line;
+	    if ($line =~ /^(\S+): 0x([0-9a-z]{4})([0-9a-z]{4}) \(0x([0-9a-z]{4})([0-9a-z]{4})\)/) {
+		my $slot = $1;
+		my $pciid = $3 . ":" . $2;
+		my $pciclass = $4;
+		foreach $controller (@controllers) {
+		    next if ($controller->{PCISLOT} ne $slot);
+		    $controller->{PCIID} = $pciid;
+		    $controller->{PCICLASS} = $pciclass;
+		}
+	    }
+	}
+        close $handle;
+    
+        return @controllers;
+    }
 }
 
 sub getPCIDeviceVendor {
