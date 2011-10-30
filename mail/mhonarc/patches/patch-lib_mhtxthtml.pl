$NetBSD: patch-lib_mhtxthtml.pl,v 1.1 2011/10/30 22:03:42 spz Exp $

--- lib/mhtxthtml.pl.orig	2011-01-09 16:12:14.000000000 +0000
+++ lib/mhtxthtml.pl
@@ -152,7 +152,8 @@ sub filter {
     my $subdir   = $args =~ /\bsubdir\b/i;
     my $norelate = $args =~ /\bdisablerelated\b/i;
     my $atdir    = $subdir ? $mhonarc::MsgPrefix.$mhonarc::MHAmsgnum : "";
-    my $tmp, $i;
+    my $tmp;
+    my $i;
 
     my $charset = $fields->{'x-mha-charset'};
     my($charcnv, $real_charset_name) =
