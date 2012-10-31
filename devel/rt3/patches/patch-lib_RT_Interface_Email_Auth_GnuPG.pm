$NetBSD: patch-lib_RT_Interface_Email_Auth_GnuPG.pm,v 1.2 2012/10/31 20:39:26 spz Exp $

perl 5.14 qw() in for* fixes

--- lib/RT/Interface/Email/Auth/GnuPG.pm.orig	2012-10-25 20:19:10.000000000 +0000
+++ lib/RT/Interface/Email/Auth/GnuPG.pm
@@ -76,11 +76,11 @@ sub GetCurrentUser {
     );
 
     foreach my $p ( $args{'Message'}->parts_DFS ) {
-        $p->head->delete($_) for qw(
+        $p->head->delete($_) for (qw(
             X-RT-GnuPG-Status X-RT-Incoming-Encryption
             X-RT-Incoming-Signature X-RT-Privacy
             X-RT-Sign X-RT-Encrypt
-        );
+        ));
     }
 
     my $msg = $args{'Message'}->dup;
