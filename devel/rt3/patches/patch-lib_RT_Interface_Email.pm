$NetBSD: patch-lib_RT_Interface_Email.pm,v 1.1 2011/10/25 19:38:10 spz Exp $

perl 5.14 qw() in for* fixes

--- lib/RT/Interface/Email.pm.orig	2011-04-14 00:32:21.000000000 +0000
+++ lib/RT/Interface/Email.pm
@@ -632,7 +632,7 @@ sub ForwardTicket {
     $txns->Limit(
         FIELD    => 'Type',
         VALUE    => $_,
-    ) for qw(Create Correspond);
+    ) for ( qw(Create Correspond) );
 
     my $entity = MIME::Entity->build(
         Type => 'multipart/mixed',
