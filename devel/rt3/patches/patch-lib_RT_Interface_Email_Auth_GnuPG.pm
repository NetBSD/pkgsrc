$NetBSD: patch-lib_RT_Interface_Email_Auth_GnuPG.pm,v 1.1 2011/10/25 19:38:10 spz Exp $

perl 5.14 qw() in for* fixes

--- lib/RT/Interface/Email/Auth/GnuPG.pm.orig	2011-04-14 00:32:21.000000000 +0000
+++ lib/RT/Interface/Email/Auth/GnuPG.pm
@@ -76,10 +76,10 @@ sub GetCurrentUser {
     );
 
     foreach my $p ( $args{'Message'}->parts_DFS ) {
-        $p->head->delete($_) for qw(
+        $p->head->delete($_) for ( qw(
             X-RT-GnuPG-Status X-RT-Incoming-Encrypton
             X-RT-Incoming-Signature X-RT-Privacy
-        );
+        ) );
     }
 
     my $msg = $args{'Message'}->dup;
