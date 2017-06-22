$NetBSD: patch-ldap_sdks_c-sdk_ldap_build_replace.pm,v 1.1 2017/06/22 16:10:39 joerg Exp $

--- ldap/sdks/c-sdk/ldap/build/replace.pm.orig	2017-06-19 13:59:54.838499230 +0000
+++ ldap/sdks/c-sdk/ldap/build/replace.pm
@@ -62,7 +62,7 @@ sub GenerateHeader ($$\%) {
     while(<TEMPLATE>) {
         my $line = $_;
         while(($orig, $replace) = each %$keywords) {
-            $line =~ s/{{$orig}}/$replace/g;
+            $line =~ s/\{\{$orig\}\}/$replace/g;
         }
 	
 	# the first line is a comment specific to the template file, which we
