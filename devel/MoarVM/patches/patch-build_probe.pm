$NetBSD: patch-build_probe.pm,v 1.2 2017/02/05 12:36:59 bsiegert Exp $

Add LDFLAGS for Configure.pl probes so e.g. finding libffi works.

--- build/probe.pm.orig	2016-11-16 14:34:28.000000000 +0000
+++ build/probe.pm
@@ -57,7 +57,7 @@ sub compile {
         push @objs, $obj;
     }
 
-    my $command = "$config->{ld} $config->{ldout}$leaf @objs $config->{ldlibs} >$devnull 2>&1";
+    my $command = "$config->{ld} $ENV{'LDFLAGS'} $config->{ldout}$leaf @objs $config->{ldlibs} >$devnull 2>&1";
     system $command
         and return;
     return 1;
@@ -102,7 +102,7 @@ EOT
     }
 
     if ($can_compile) {
-        $command = "$config->{ld} $config->{ldout}$leaf $obj $config->{ldlibs} 2>&1";
+        $command = "$config->{ld} $ENV{'LDFLAGS'} $config->{ldout}$leaf $obj $config->{ldlibs} 2>&1";
         $output  = `$command` || $!;
         if ($? >> 8 == 0) {
             $can_link = 1;
