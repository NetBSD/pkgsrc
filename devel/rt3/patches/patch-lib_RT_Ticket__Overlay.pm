$NetBSD: patch-lib_RT_Ticket__Overlay.pm,v 1.1 2011/10/25 19:38:10 spz Exp $

perl 5.14 qw() in for* fixes

--- lib/RT/Ticket_Overlay.pm.orig	2011-04-14 00:32:21.000000000 +0000
+++ lib/RT/Ticket_Overlay.pm
@@ -471,13 +471,13 @@ sub Create {
     );
 
 # Parameters passed in during an import that we probably don't want to touch, otherwise
-    foreach my $attr qw(id Creator Created LastUpdated LastUpdatedBy) {
+    foreach my $attr ( qw(id Creator Created LastUpdated LastUpdatedBy) ) {
         $params{$attr} = $args{$attr} if $args{$attr};
     }
 
     # Delete null integer parameters
     foreach my $attr
-        qw(TimeWorked TimeLeft TimeEstimated InitialPriority FinalPriority)
+        ( qw(TimeWorked TimeLeft TimeEstimated InitialPriority FinalPriority) )
     {
         delete $params{$attr}
           unless ( exists $params{$attr} && $params{$attr} );
@@ -745,7 +745,7 @@ sub _Parse822HeadersForAttributes {
         
     }
 
-    foreach my $date qw(due starts started resolved) {
+    foreach my $date ( qw(due starts started resolved) ) {
         my $dateobj = RT::Date->new($RT::SystemUser);
         if ( defined ($args{$date}) and $args{$date} =~ /^\d+$/ ) {
             $dateobj->Set( Format => 'unix', Value => $args{$date} );
@@ -2600,7 +2600,7 @@ sub MergeInto {
     }
 
     # Update time fields
-    foreach my $type qw(TimeEstimated TimeWorked TimeLeft) {
+    foreach my $type ( qw(TimeEstimated TimeWorked TimeLeft) ) {
 
         my $mutator = "Set$type";
         $MergeInto->$mutator(
@@ -2608,7 +2608,7 @@ sub MergeInto {
 
     }
 #add all of this ticket's watchers to that ticket.
-    foreach my $watcher_type qw(Requestors Cc AdminCc) {
+    foreach my $watcher_type ( qw(Requestors Cc AdminCc) ) {
 
         my $people = $self->$watcher_type->MembersObj;
         my $addwatcher_type =  $watcher_type;
