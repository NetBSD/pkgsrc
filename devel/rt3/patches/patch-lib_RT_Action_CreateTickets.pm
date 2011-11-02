$NetBSD: patch-lib_RT_Action_CreateTickets.pm,v 1.1.2.2 2011/11/02 22:52:22 tron Exp $

perl 5.14 qw() in for* fixes

--- lib/RT/Action/CreateTickets.pm.orig	2011-04-14 00:32:21.000000000 +0000
+++ lib/RT/Action/CreateTickets.pm
@@ -723,7 +723,7 @@ sub ParseLines {
         }
     }
 
-    foreach my $date qw(due starts started resolved) {
+    foreach my $date ( qw(due starts started resolved) ) {
         my $dateobj = RT::Date->new( $self->CurrentUser );
         next unless $args{$date};
         if ( $args{$date} =~ /^\d+$/ ) {
@@ -1080,7 +1080,7 @@ sub UpdateWatchers {
 
     my @results;
 
-    foreach my $type qw(Requestor Cc AdminCc) {
+    foreach my $type ( qw(Requestor Cc AdminCc) ) {
         my $method  = $type . 'Addresses';
         my $oldaddr = $ticket->$method;
 
