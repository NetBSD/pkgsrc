$NetBSD: patch-Build.PL,v 1.1 2022/07/29 05:59:41 rin Exp $

Switch to `pkg-config imlib2`.

--- Build.PL.orig	2022-07-29 03:28:43.811840721 +0900
+++ Build.PL	2022-07-29 03:29:38.258526933 +0900
@@ -1,10 +1,10 @@
 use Module::Build;
 use strict;
 
-# We need to find imlib2-config
-my $CONFIG = "imlib2-config";
+# We need to find pkg-config
+my $CONFIG = "pkg-config";
 
-my $version = `$CONFIG --version`;
+my $version = `$CONFIG imlib2 --modversion`;
 if (!$version) {
   warn 'You must install the imlib2 library before you can install
 Image::Imlib2. You can obtain imlib2 from
@@ -19,8 +19,8 @@
   print "Found imlib2 $version";
 }
 
-my $libs = `$CONFIG --libs`;
-my $cflags = "-DX_DISPLAY_MISSING " . `$CONFIG --cflags`;
+my $libs = `$CONFIG imlib2 --libs`;
+my $cflags = "-DX_DISPLAY_MISSING " . `$CONFIG imlib2 --cflags`;
 
 my $build = Module::Build->new(
   c_source     => './lib/Image',
