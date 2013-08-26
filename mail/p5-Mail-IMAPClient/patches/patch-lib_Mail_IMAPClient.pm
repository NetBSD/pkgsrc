$NetBSD: patch-lib_Mail_IMAPClient.pm,v 1.1 2013/08/26 09:58:08 abs Exp $

Set MultiHomed => 1 in call to IO::Socket::INET to allow fallback to IPv4
when server has both IPv4 and IPv6 addresses and no reliable IPv6 route

--- lib/Mail/IMAPClient.pm.orig	2013-05-14 14:27:09.000000000 +0000
+++ lib/Mail/IMAPClient.pm
@@ -356,6 +356,7 @@ sub connect(@) {
                 PeerPort => $port,
                 Proto    => 'tcp',
                 Debug    => $self->Debug,
+                MultiHomed => 1,
                 @timeout,
                 @args
             );
