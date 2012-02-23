$NetBSD: patch-dist_ExtUtils_CBuilder_t_04-base.t,v 1.1 2012/02/23 13:00:23 fhajny Exp $

EU::CBuilder shouldn't override ccflags with CFLAGS (2/2)
https://rt.perl.org/rt3//Public/Bug/Display.html?id=89478
--- dist/ExtUtils-CBuilder/t/04-base.t.orig	2011-09-26 09:44:34.000000000 +0000
+++ dist/ExtUtils-CBuilder/t/04-base.t
@@ -1,7 +1,7 @@
 #! perl -w
 
 use strict;
-use Test::More tests => 50;
+use Test::More tests => 64;
 use Config;
 use Cwd;
 use File::Path qw( mkpath );
@@ -328,6 +328,29 @@ is_deeply( $mksymlists_args,
     "_prepare_mksymlists_args(): got expected arguments for Mksymlists",
 );
 
+my %testvars = (
+    CFLAGS  => 'ccflags',
+    LDFLAGS => 'ldflags',
+);
+
+while (my ($VAR, $var) = each %testvars) {
+    local $ENV{$VAR};
+    $base = ExtUtils::CBuilder::Base->new( quiet => 1 );
+    ok( $base, "ExtUtils::CBuilder::Base->new() returned true value" );
+    isa_ok( $base, 'ExtUtils::CBuilder::Base' );
+    like($base->{config}{$var}, qr/\Q$Config{$var}/,
+        "honours $var from Config.pm");
+
+    $ENV{$VAR} = "-foo -bar";
+    $base = ExtUtils::CBuilder::Base->new( quiet => 1 );
+    ok( $base, "ExtUtils::CBuilder::Base->new() returned true value" );
+    isa_ok( $base, 'ExtUtils::CBuilder::Base' );
+    like($base->{config}{$var}, qr/\Q$ENV{$VAR}/,
+        "honours $VAR from the environment");
+    like($base->{config}{$var}, qr/\Q$Config{$var}/,
+        "doesn't override $var from Config.pm with $VAR from the environment");
+}
+
 #####
 
 for ($source_file, $object_file, $lib_file) {
