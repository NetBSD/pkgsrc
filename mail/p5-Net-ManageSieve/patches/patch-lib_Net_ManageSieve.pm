$NetBSD: patch-lib_Net_ManageSieve.pm,v 1.3 2026/03/22 21:32:01 markd Exp $

If checking certificate, need to explicitly set the hostname we should use

--- lib/Net/ManageSieve.pm.orig	2016-01-04 10:51:50.000000000 +0000
+++ lib/Net/ManageSieve.pm
@@ -340,7 +340,7 @@ sub starttls {
 		}
 	}
 
-	IO::Socket::SSL->start_SSL($self->{fh} , %opts);
+	IO::Socket::SSL->start_SSL($self->{fh} , SSL_hostname => $self->{host} , %opts);
 	# In-place upgrade of socket
 	return undef unless ref($self->{fh}) eq 'IO::Socket::SSL';
 
