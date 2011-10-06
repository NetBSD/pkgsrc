$NetBSD: patch-lib_Crypt_DSA_Util.pm,v 1.1 2011/10/06 19:22:02 gls Exp $

Fix for SA46275, taken from https://rt.cpan.org/Public/Bug/Display.html?id=71421

--- lib/Crypt/DSA/Util.pm.orig	2011-06-17 01:46:42.000000000 +0000
+++ lib/Crypt/DSA/Util.pm
@@ -64,11 +64,8 @@ sub makerandom {
         }
         close $fh;
     }
-    elsif ( require Data::Random ) {
-        $r .= Data::Random::rand_chars( set=>'numeric' ) for 1..$bytes;
-    }
     else {
-        croak "makerandom requires /dev/random or Data::Random";
+        croak "makerandom requires /dev/random";
     }
     my $down = $size - 1;
     $r = unpack 'H*', pack 'B*', '0' x ( $size % 8 ? 8 - $size % 8 : 0 ) .
