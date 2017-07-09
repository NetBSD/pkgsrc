$NetBSD: patch-Makefile.PL,v 1.1 2017/07/09 17:17:06 schmonz Exp $

This check fails on OS X, but the code otherwise builds and passes
its tests. Let pkgsrc decide whether the OS has kqueue(2).

--- Makefile.PL.orig	2005-02-17 22:15:36.000000000 +0000
+++ Makefile.PL
@@ -3,19 +3,19 @@
 use strict;
 use ExtUtils::MakeMaker;
 
-eval { require 'syscall.ph'; 1 } || eval { require 'sys/syscall.ph'; 1 };
-
-my $SYS_kqueue = eval { &::SYS_kqueue } || 362;
-
-my $kq = eval { syscall($SYS_kqueue) };
-
-if ($@) {
-    print <<EOT;
-No kqueue() available on this platform.
-
-EOT
-    exit;
-}
+#eval { require 'syscall.ph'; 1 } || eval { require 'sys/syscall.ph'; 1 };
+#
+#my $SYS_kqueue = eval { &::SYS_kqueue } || 362;
+#
+#my $kq = eval { syscall($SYS_kqueue) };
+#
+#if ($@) {
+#    print <<EOT;
+#No kqueue() available on this platform.
+#
+#EOT
+#    exit;
+#}
 
 WriteMakefile(
     VERSION_FROM   => 'KQueue.pm',
