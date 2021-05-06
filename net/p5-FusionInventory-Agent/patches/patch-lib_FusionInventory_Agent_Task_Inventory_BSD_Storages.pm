$NetBSD: patch-lib_FusionInventory_Agent_Task_Inventory_BSD_Storages.pm,v 1.1 2021/05/06 20:25:15 bouyer Exp $

Use /var/run/dmesg.boot if present
Use sysctl hw.disknames if present
match NetBSD disk names

--- lib/FusionInventory/Agent/Task/Inventory/BSD/Storages.pm.orig	2020-08-04 09:36:42.000000000 +0200
+++ lib/FusionInventory/Agent/Task/Inventory/BSD/Storages.pm	2021-05-06 22:14:19.168779300 +0200
@@ -37,38 +37,68 @@
         command => $command,
         %params
     );
-    $lines =~ s/^kern.geom.confxml://;
-    my $tpp = XML::TreePP->new();
-    my $tree = $tpp->parse($lines);
-
-    my @storages = ();
-    for my $class (@{$tree->{mesh}->{class}}) {
-        my $name = $class->{name} || $class->{'#name'} || '';
-        next unless ($name && $name eq 'DISK');
-        for my $geom (@{$class->{geom}}) {
-            my $device = {};
-            $device->{NAME} = $geom->{name} if $geom->{name};
-            $device->{DESCRIPTION} = $geom->{provider}->{config}->{descr}
-                if ($geom->{provider}
-                    && $geom->{provider}->{config}
-                    && $geom->{provider}->{config}->{descr});
-            $device->{DISKSIZE} = $geom->{provider}->{mediasize}
-                if ($geom->{provider}
-                    && defined $geom->{provider}->{mediasize});
-            $device->{TYPE} = _retrieveDeviceTypeFromName($device->{NAME});
-            push @storages, $device;
+    if ($lines =~ /^kern.geom.confxml:/) {
+        $lines =~ s/^kern.geom.confxml://;
+        my $tpp = XML::TreePP->new();
+        my $tree = $tpp->parse($lines);
+    
+        my @storages = ();
+        for my $class (@{$tree->{mesh}->{class}}) {
+            my $name = $class->{name} || $class->{'#name'} || '';
+            next unless ($name && $name eq 'DISK');
+            for my $geom (@{$class->{geom}}) {
+                my $device = {};
+                $device->{NAME} = $geom->{name} if $geom->{name};
+                $device->{DESCRIPTION} = $geom->{provider}->{config}->{descr}
+                    if ($geom->{provider}
+                        && $geom->{provider}->{config}
+                        && $geom->{provider}->{config}->{descr});
+                $device->{DISKSIZE} = $geom->{provider}->{mediasize}
+                    if ($geom->{provider}
+                        && defined $geom->{provider}->{mediasize});
+                $device->{TYPE} = _retrieveDeviceTypeFromName($device->{NAME});
+                push @storages, $device;
+            }
         }
+    
+        # Unittest support
+        $params{file} = $params{dmesgFile} if ($params{dmesgFile});
+    
+        _extractDataFromDmesg(
+            storages => \@storages,
+            %params
+        );
+    
+        return @storages;
     }
-
-    # Unittest support
-    $params{file} = $params{dmesgFile} if ($params{dmesgFile});
-
-    _extractDataFromDmesg(
-        storages => \@storages,
+    $command = 'sysctl hw.disknames';
+    $lines = getAllLines(
+        command => $command,
         %params
     );
-
-    return @storages;
+    if ($lines =~ /^hw.disknames = /) {
+        $lines =~ s/^hw.disknames = //;
+	chop $lines;
+        my @storages = ();
+	foreach my $drive (split / /, $lines) {
+	    
+	    next if $drive =~ /^vnd/;
+	    next if $drive =~ /^dk/;
+	    next if $drive =~ /^raid/;
+	    next if $drive =~ /^cgd/;
+	    next if $drive =~ /^ccd/;
+	    next if $drive =~ /^dm/;
+            my $device->{NAME} = $drive;
+            push @storages, $device;
+        }
+    
+        _extractDataFromDmesg(
+            storages => \@storages,
+            %params
+        );
+    
+        return @storages;
+    }
 }
 
 sub _retrieveDeviceTypeFromName {
@@ -76,6 +106,10 @@
     my $type = not (defined $name) ? 'unknown' :
             $name =~ /^da/ ? 'disk' :
             $name =~ /^ada/ ? 'disk' :
+            $name =~ /^wd/ ? 'disk' :
+            $name =~ /^sd/ ? 'disk' :
+            $name =~ /^ld/ ? 'disk' :
+            $name =~ /^xbd/ ? 'disk' :
             $name =~ /^cd/ ? 'cdrom' :
                 'unknown';
     return $type;
@@ -85,11 +119,19 @@
     my (%params) = @_;
 
     my $storages = $params{storages};
+    my $dmesgLines;
 
-    my $dmesgLines = getAllLines(
-        command => 'dmesg',
-        %params
-    );
+    if ( -r "/var/run/dmesg.boot") {
+        $dmesgLines = getAllLines(
+            file => '/var/run/dmesg.boot',
+            %params
+        );
+    } else {
+        $dmesgLines = getAllLines(
+            command => 'dmesg',
+            %params
+        );
+    }
     for my $storage (@$storages) {
         next unless $storage->{NAME};
         $storage->{MODEL} = getFirstMatch(
@@ -105,6 +147,14 @@
             string => $dmesgLines,
             pattern => qr/^\Q$storage->{NAME}\E: Serial Number (.*)$/
         ) || '';
+	
+	if (!defined($storage->{DISKSIZE})) {
+            my $size = getFirstMatch(
+                string => $dmesgLines,
+                pattern => qr/^\Q$storage->{NAME}\E: .* (\d+) sectors/
+            );
+	    $storage->{DISKSIZE} = $size / 2048; # in MB
+        }
 
         if ($storage->{MODEL}) {
             if ($storage->{MODEL} =~ s/^(SGI|SONY|WDC|ASUS|LG|TEAC|SAMSUNG|PHILIPS|PIONEER|MAXTOR|PLEXTOR|SEAGATE|IBM|SUN|SGI|DEC|FUJITSU|TOSHIBA|YAMAHA|HITACHI|VERITAS)\s*//i) {
