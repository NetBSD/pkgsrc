$NetBSD: patch-lib_Mail_SpamAssassin_DnsResolver.pm,v 1.3.2.2 2014/10/10 10:56:05 spz Exp $

Make this work with Net::DNS 0.76 or newer.

Patch taken from SVN repository:

https://svn.apache.org/viewvc/spamassassin/trunk/lib/Mail/SpamAssassin/DnsResolver.pm?r1=1603518&r2=1603517&pathrev=1603518

--- lib/Mail/SpamAssassin/DnsResolver.pm.orig	2014-02-07 08:36:28.000000000 +0000
+++ lib/Mail/SpamAssassin/DnsResolver.pm	2014-10-01 09:35:33.000000000 +0100
@@ -204,8 +204,10 @@
     @ns_addr_port = @{$self->{conf}->{dns_servers}};
     dbg("dns: servers set by config to: %s", join(', ',@ns_addr_port));
   } elsif ($res) {  # default as provided by Net::DNS, e.g. /etc/resolv.conf
-    @ns_addr_port = map(untaint_var("[$_]:" . $res->{port}),
-                        @{$res->{nameservers}});
+    my @ns = $res->UNIVERSAL::can('nameservers') ? $res->nameservers
+                                                 : @{$res->{nameservers}};
+    my $port = $res->UNIVERSAL::can('port') ? $res->port : $res->{port};
+    @ns_addr_port = map(untaint_var("[$_]:" . $port), @ns);
     dbg("dns: servers obtained from Net::DNS : %s", join(', ',@ns_addr_port));
   }
   return @ns_addr_port;
