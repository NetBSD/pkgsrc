$NetBSD: patch-t_file__contains__encoded.t,v 1.1 2014/09/12 08:49:52 wen Exp $
Make test work.
--- t/file_contains_encoded.t.orig	2014-09-12 16:34:24.000000000 +0000
+++ t/file_contains_encoded.t
@@ -12,7 +12,7 @@ my $string1 = 'Привет мир!';
 my $string2 = 'Я строкой';
 my $encoding = 'KOI8-R';
 
-require 'setup_common';
+require 't/setup_common';
 
 my $file = '$file';
 open my $fh, '>', $file or print "bail out! Could not write to $file: $!";
