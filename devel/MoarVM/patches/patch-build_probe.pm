$NetBSD: patch-build_probe.pm,v 1.1 2016/04/08 20:26:46 bsiegert Exp $

Add LDFLAGS for Configure.pl probes so e.g. finding libffi works.

--- build/probe.pm.orig	2015-12-25 12:37:32.000000000 +0000
+++ build/probe.pm
@@ -57,7 +57,7 @@ sub compile {
         push @objs, $obj;
     }
 
-    my $command = "$config->{ld} $config->{ldout}$leaf @objs $config->{ldlibs} >$devnull 2>&1";
+    my $command = "$config->{ld} $ENV{'LDFLAGS'} $config->{ldout}$leaf @objs $config->{ldlibs} >$devnull 2>&1";
     system $command
         and return;
     return 1;
