$NetBSD: patch-cpan_Digest_Digest.pm,v 1.1.2.2 2011/11/02 21:50:23 tron Exp $

taken from:
http://http://perl5.git.perl.org/perl.git/commitdiff/a2fa999d41c94d622051667d897fedca90be1828

--- cpan/Digest/Digest.pm.orig	2010-12-30 02:07:15.000000000 +0000
+++ cpan/Digest/Digest.pm
@@ -3,7 +3,7 @@ package Digest;
 use strict;
 use vars qw($VERSION %MMAP $AUTOLOAD);
 
-$VERSION = "1.16";
+$VERSION = "1.17";
 
 %MMAP = (
   "SHA-1"      => [["Digest::SHA", 1], "Digest::SHA1", ["Digest::SHA2", 1]],
@@ -16,7 +16,7 @@ $VERSION = "1.16";
   "CRC-16"     => [["Digest::CRC", type => "crc16"]],
   "CRC-32"     => [["Digest::CRC", type => "crc32"]],
   "CRC-CCITT"  => [["Digest::CRC", type => "crcccitt"]],
-  "RIPEMD-160" => "Crypt::PIPEMD160",
+  "RIPEMD-160" => "Crypt::RIPEMD160",
 );
 
 sub new
@@ -24,10 +24,11 @@ sub new
     shift;  # class ignored
     my $algorithm = shift;
     my $impl = $MMAP{$algorithm} || do {
-	$algorithm =~ s/\W+//;
+	$algorithm =~ s/\W+//g;
 	"Digest::$algorithm";
     };
     $impl = [$impl] unless ref($impl);
+    local $@;  # don't clobber it for our caller
     my $err;
     for  (@$impl) {
 	my $class = $_;
@@ -35,7 +36,9 @@ sub new
 	($class, @args) = @$class if ref($class);
 	no strict 'refs';
 	unless (exists ${"$class\::"}{"VERSION"}) {
-	    eval "require $class";
+	    my $pm_file = $class . ".pm";
+	    $pm_file =~ s{::}{/}g;
+	    eval { require $pm_file };
 	    if ($@) {
 		$err ||= $@;
 		next;
