$NetBSD: patch-lib_RT_Squish.pm,v 1.1 2026/10/14 19:33:35 markd Exp $

fix for Plack > 1.0051
https://forum.bestpractical.com/t/wide-character-error-in-rt-squish/41631/3

--- lib/RT/Squish.pm.orig	2025-04-29 14:01:56.000000000 +0000
+++ lib/RT/Squish.pm
@@ -82,7 +82,7 @@ sub new {
 
     my $content = $self->Squish;
     $self->Content($content);
-    $self->Key( md5_hex $content );
+    $self->Key( md5_hex Encode::encode_utf8 $content );
     $self->ModifiedTime( time() );
     $self->ModifiedTimeString( HTTP::Date::time2str( $self->ModifiedTime ) );
     return $self;
