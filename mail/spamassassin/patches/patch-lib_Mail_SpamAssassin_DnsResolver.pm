$NetBSD: patch-lib_Mail_SpamAssassin_DnsResolver.pm,v 1.1 2013/12/04 15:14:19 jperkin Exp $

Part of backport of bug#6937

--- lib/Mail/SpamAssassin/DnsResolver.pm.orig	2011-06-06 23:59:17.000000000 +0000
+++ lib/Mail/SpamAssassin/DnsResolver.pm
@@ -440,10 +440,16 @@ sub poll_responses {
     { my $timer;  # collects timestamp when variable goes out of scope
       if (!defined($timeout) || $timeout > 0)
         { $timer = $self->{main}->time_method("poll_dns_idle") }
+      $! = 0;
       ($nfound, $timeleft) = select($rout=$rin, undef, undef, $timeout);
     }
     if (!defined $nfound || $nfound < 0) {
-      warn "dns: select failed: $!";
+      if ($!) { warn "dns: select failed: $!\n" }
+      else    { info("dns: select interrupted") }
+      return;
+    } elsif (!$nfound) {
+      if (!defined $timeout) { warn("dns: select returned empty-handed\n") }
+      elsif ($timeout > 0) { dbg("dns: select timed out %.3f s", $timeout) }
       return;
     }
 
