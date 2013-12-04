$NetBSD: patch-lib_Mail_SpamAssassin_AsyncLoop.pm,v 1.1 2013/12/04 15:14:19 jperkin Exp $

Part of backport of bug#6937

--- lib/Mail/SpamAssassin/AsyncLoop.pm.orig	2011-06-06 23:59:17.000000000 +0000
+++ lib/Mail/SpamAssassin/AsyncLoop.pm
@@ -360,7 +360,13 @@ sub complete_lookups {
     }
     $now = time;  # capture new timestamp, after possible sleep in 'select'
 
-    while (my($key,$ent) = each %$pending) {
+    # A callback routine may generate another DNS query, which may insert
+    # an entry into the %$pending hash thus invalidating the each() context.
+    # So, make sure that callbacks are not called while the each() context
+    # is open, or avoid using each().  [Bug 6937]
+    #
+    foreach my $key (keys %$pending) {
+      my $ent = $pending->{$key};
       my $id = $ent->{id};
       if (defined $ent->{poll_callback}) {  # call a "poll_callback" if exists
         # be nice, provide fresh info to a callback routine
@@ -448,7 +454,8 @@ sub abort_remaining_lookups {
   my $pending = $self->{pending_lookups};
   my $foundcnt = 0;
   my $now = time;
-  while (my($key,$ent) = each %$pending) {
+  foreach my $key (keys %$pending) {
+    my $ent = $pending->{$key};
     dbg("async: aborting after %.3f s, %s: %s",
         $now - $ent->{start_time},
         (defined $ent->{timeout_initial} &&
