$NetBSD: patch-lib_File_Find_Rule.pm,v 1.1 2025/06/05 19:00:01 wiz Exp $

File::Find::Rule through 0.34 for Perl is vulnerable to Arbitrary Code
Execution when `grep()` encounters a crafted file name

CVE-2011-10007
https://github.com/richardc/perl-file-find-rule/commit/df58128bcee4c1da78c34d7f3fe1357e575ad56f.patch

--- lib/File/Find/Rule.pm.orig	2015-12-03 14:27:56.000000000 +0000
+++ lib/File/Find/Rule.pm
@@ -420,7 +420,7 @@ sub grep {
 
     $self->exec( sub {
         local *FILE;
-        open FILE, $_ or return;
+        open FILE, '<', $_ or return;
         local ($_, $.);
         while (<FILE>) {
             for my $p (@pattern) {
