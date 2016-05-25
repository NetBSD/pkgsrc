$NetBSD: patch-hitch.conf.ex,v 1.1 2016/05/25 20:15:35 fhajny Exp $

Sane default options.

--- hitch.conf.ex.orig	2016-03-18 17:55:17.000000000 +0000
+++ hitch.conf.ex
@@ -43,7 +43,7 @@ backend = "[127.0.0.1]:6081"
 # only available for a specific listen endpoint.
 #
 # type: string
-pem-file = ""
+pem-file = "@HITCH_CERTS@"
 
 # SSL protocol.
 #
@@ -94,12 +94,12 @@ chroot = ""
 # Set uid after binding a socket
 #
 # type: string
-user = ""
+user = "@HITCH_USER@"
 
 # Set gid after binding a socket
 #
 # type: string
-group = ""
+group = "@HITCH_GROUP@"
 
 # Quiet execution, report only error messages
 #
@@ -109,7 +109,7 @@ quiet = off
 # Use syslog for logging
 #
 # type: boolean
-syslog = off
+syslog = on
 
 # Syslog facility to use
 #
@@ -119,7 +119,7 @@ syslog-facility = "daemon"
 # Run as daemon
 #
 # type: boolean
-daemon = off
+daemon = on
 
 # Report client address by writing IP before sending data
 #
