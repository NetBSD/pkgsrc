$NetBSD: patch-lib_RT_Interface_Web.pm,v 1.1 2017/03/12 19:55:49 spz Exp $

--- lib/RT/Interface/Web.pm.orig	2013-05-22 19:03:04.000000000 +0000
+++ lib/RT/Interface/Web.pm
@@ -2591,7 +2591,7 @@ sub GetColumnMapEntry {
     }
 
     # complex things
-    elsif ( my ( $mainkey, $subkey ) = $args{'Name'} =~ /^(.*?)\.{(.+)}$/ ) {
+    elsif ( my ( $mainkey, $subkey ) = $args{'Name'} =~ /^(.*?)\.\{(.+)}$/ ) {
         return undef unless $args{'Map'}->{$mainkey};
         return $args{'Map'}{$mainkey}{ $args{'Attribute'} }
             unless ref $args{'Map'}{$mainkey}{ $args{'Attribute'} } eq 'CODE';
