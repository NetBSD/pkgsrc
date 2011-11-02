$NetBSD: patch-lib_RT_Transaction__Overlay.pm,v 1.1.2.2 2011/11/02 22:52:22 tron Exp $

perl 5.14 qw() in for* fixes

--- lib/RT/Transaction_Overlay.pm.orig	2011-04-14 00:32:21.000000000 +0000
+++ lib/RT/Transaction_Overlay.pm
@@ -144,7 +144,7 @@ sub Create {
     );
 
     # Parameters passed in during an import that we probably don't want to touch, otherwise
-    foreach my $attr qw(id Creator Created LastUpdated TimeTaken LastUpdatedBy) {
+    foreach my $attr ( qw(id Creator Created LastUpdated TimeTaken LastUpdatedBy) ) {
         $params{$attr} = $args{$attr} if ($args{$attr});
     }
  
