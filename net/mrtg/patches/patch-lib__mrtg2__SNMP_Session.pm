$NetBSD: patch-lib__mrtg2__SNMP_Session.pm,v 1.1 2013/08/03 17:05:17 tron Exp $

Fix run-time warnings under Perl 5.16 and newer caused by the IPv6 support
in the "Socket" module.

--- lib/mrtg2/SNMP_Session.pm.orig	2012-01-12 10:29:00.000000000 +0000
+++ lib/mrtg2/SNMP_Session.pm	2013-08-03 17:56:14.000000000 +0100
@@ -146,7 +146,7 @@
 
     if (eval {local $SIG{__DIE__};require Socket6;} &&
        eval {local $SIG{__DIE__};require IO::Socket::INET6; IO::Socket::INET6->VERSION("1.26");}) {
-       Socket6->import(qw(pack_sockaddr_in6 inet_pton getaddrinfo unpack_sockaddr_in6));
+       Socket6->import(qw(inet_pton getaddrinfo));
 	$ipv6_addr_len = length(pack_sockaddr_in6(161, inet_pton(AF_INET6(), "::1")));
 	$SNMP_Session::ipv6available = 1;
     }
@@ -601,7 +601,7 @@
 BEGIN {
     if($SNMP_Session::ipv6available) {
 	    import IO::Socket::INET6;
-        Socket6->import(qw(pack_sockaddr_in6 inet_pton getaddrinfo unpack_sockaddr_in6));
+        Socket6->import(qw(inet_pton getaddrinfo));
     }
 }
 
