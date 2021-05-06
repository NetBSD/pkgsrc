$NetBSD: patch-lib_FusionInventory_Agent_Tools_BSD.pm,v 1.1 2021/05/06 20:25:15 bouyer Exp $

Support NetBSD's ifconfig output

--- lib/FusionInventory/Agent/Tools/BSD.pm.orig	2020-08-04 09:36:42.000000000 +0200
+++ lib/FusionInventory/Agent/Tools/BSD.pm	2021-05-05 00:51:31.393670504 +0200
@@ -31,7 +31,7 @@
     );
 
     while (my $line = <$handle>) {
-        if ($line =~ /^(\S+): flags=\d+<([^>]+)> (?:metric \d+ )?mtu (\d+)/) {
+        if ($line =~ /^(\S+): flags=(?:0x)?[A-Fa-f\d]+<([^>]+)> (?:metric \d+ )?mtu (\d+)/) {
 
             if (@addresses) {
                 push @interfaces, @addresses;
@@ -75,6 +75,23 @@
                 MACADDR     => $interface->{MACADDR},
                 MTU         => $interface->{MTU}
             };
+        } elsif ($line =~ /inet ($ip_address_pattern)\/(\d+) (?:--> $ip_address_pattern )?/) {
+            my $address = $1;
+            my $netbit=$2;
+            my $mask  = (2 ** $2 - 1) << (32 - $2);
+            my $netmask = unpack("H8", pack( "N", $mask));
+            $mask    = hex2canonical($netmask);
+            my $subnet  = getSubnetAddress($address, $mask);
+
+            push @addresses, {
+                IPADDRESS   => $address,
+                IPMASK      => $mask,
+                IPSUBNET    => $subnet,
+                STATUS      => $interface->{STATUS},
+                DESCRIPTION => $interface->{DESCRIPTION},
+                MACADDR     => $interface->{MACADDR},
+                MTU         => $interface->{MTU}
+            };
         } elsif ($line =~ /inet6 ([\w:]+)\S* prefixlen (\d+)/) {
             my $address = $1;
             my $mask    = getNetworkMaskIPv6($2);
