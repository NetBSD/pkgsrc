$NetBSD: patch-lib_RT_Condition.pm,v 1.1 2022/08/21 20:52:52 markd Exp $

fix required for perl 5.36+

--- lib/RT/Condition.pm.orig	2019-01-31 14:39:47.000000000 +0000
+++ lib/RT/Condition.pm
@@ -198,7 +198,7 @@ sub DESTROY {
 
     # We need to clean up all the references that might maybe get
     # oddly circular
-    $self->{'TemplateObj'} =undef
+    $self->{'TemplateObj'} = undef;
     $self->{'TicketObj'} = undef;
     $self->{'TransactionObj'} = undef;
     $self->{'ScripObj'} = undef;
