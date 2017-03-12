$NetBSD: patch-lib_RT_Date.pm,v 1.1 2017/03/12 19:55:49 spz Exp $

--- lib/RT/Date.pm.orig	2013-05-22 19:03:04.000000000 +0000
+++ lib/RT/Date.pm
@@ -753,7 +753,7 @@ sub ISO {
     my $res = '';
     $res .= sprintf("%04d-%02d-%02d", $year, $mon, $mday) if $args{'Date'};
     $res .= sprintf(' %02d:%02d', $hour, $min) if $args{'Time'};
-    $res .= sprintf(':%02d', $sec, $min) if $args{'Time'} && $args{'Seconds'};
+    $res .= sprintf(':%02d', $sec) if $args{'Time'} && $args{'Seconds'};
     $res =~ s/^\s+//;
 
     return $res;
