$NetBSD: patch-lib_RT_CustomFieldValues_External.pm,v 1.1.2.2 2011/11/02 22:52:22 tron Exp $

perl 5.14 qw() in for* fixes

--- lib/RT/CustomFieldValues/External.pm.orig	2011-04-14 00:32:21.000000000 +0000
+++ lib/RT/CustomFieldValues/External.pm
@@ -94,10 +94,10 @@ sub _Init {
 
 sub CleanSlate {
     my $self = shift;
-    delete $self->{ $_ } foreach qw(
+    delete $self->{ $_ } foreach ( qw(
         __external_cf
         __external_cf_limits
-    );
+    ) );
     return $self->SUPER::CleanSlate(@_);
 }
 
