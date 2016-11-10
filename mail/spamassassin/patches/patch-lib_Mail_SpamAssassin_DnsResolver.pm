$NetBSD: patch-lib_Mail_SpamAssassin_DnsResolver.pm,v 1.5 2016/11/10 20:25:50 roy Exp $

Taken from upstream to fix using newer Net::DNS

--- lib/Mail/SpamAssassin/DnsResolver.pm.orig	2016-11-10 20:06:02.000000000 +0000
+++ lib/Mail/SpamAssassin/DnsResolver.pm
@@ -592,6 +592,9 @@ sub new_dns_packet {
   };
 
   if ($packet) {
+    # RD flag needs to be set explicitly since Net::DNS 1.01, Bug 7223
+    $packet->header->rd(1);
+
   # my $udp_payload_size = $self->{res}->udppacketsize;
     my $udp_payload_size = $self->{conf}->{dns_options}->{edns};
     if ($udp_payload_size && $udp_payload_size > 512) {
