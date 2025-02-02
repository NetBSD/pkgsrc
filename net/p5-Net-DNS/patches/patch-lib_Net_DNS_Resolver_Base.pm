$NetBSD: patch-lib_Net_DNS_Resolver_Base.pm,v 1.1 2025/02/02 11:33:56 he Exp $

Work around "Use of uninitialized value" error.
Reported upstream as rt.cpan.org #158706.

--- lib/Net/DNS/Resolver/Base.pm.orig	2025-02-02 11:30:42.750616178 +0000
+++ lib/Net/DNS/Resolver/Base.pm
@@ -525,6 +525,7 @@ NAMESERVER: foreach my $ns (@ns) {
 				my $buffer = _read_udp($socket);
 
 				my $peer = $self->{replyfrom} = $socket->peerhost;
+				if (!$peer) { $peer = ""; }
 				$self->_diag( "packet from [$peer]", length($buffer), 'octets' );
 
 				my $packet = Net::DNS::Packet->decode( \$buffer, $self->{debug} );
