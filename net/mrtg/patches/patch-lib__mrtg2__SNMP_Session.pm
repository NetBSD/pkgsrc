$NetBSD: patch-lib__mrtg2__SNMP_Session.pm,v 1.2 2019/04/14 21:50:36 jnemeth Exp $

Fix run-time warnings under Perl 5.16 and newer caused by the IPv6 support
in the "Socket" module.

--- lib/mrtg2/SNMP_Session.pm.orig	2018-07-13 06:09:56.000000000 +0000
+++ lib/mrtg2/SNMP_Session.pm
@@ -146,7 +146,7 @@ BEGIN {
 
     if (eval {local $SIG{__DIE__};require Socket6;} &&
        eval {local $SIG{__DIE__};require IO::Socket::INET6; IO::Socket::INET6->VERSION("1.26");}) {
-       Socket6->import(qw(pack_sockaddr_in6 inet_pton getaddrinfo));
+       Socket6->import(qw(inet_pton getaddrinfo));
 	$ipv6_addr_len = length(pack_sockaddr_in6(161, inet_pton(AF_INET6(), "::1")));
 	$SNMP_Session::ipv6available = 1;
     }
@@ -601,7 +601,7 @@ use Carp;
 BEGIN {
     if($SNMP_Session::ipv6available) {
 	    import IO::Socket::INET6;
-        Socket6->import(qw(pack_sockaddr_in6 inet_pton getaddrinfo));
+        Socket6->import(qw(inet_pton getaddrinfo));
     }
 }
 
