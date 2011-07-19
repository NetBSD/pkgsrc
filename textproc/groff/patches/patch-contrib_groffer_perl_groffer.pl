$NetBSD: patch-contrib_groffer_perl_groffer.pl,v 1.1 2011/07/19 21:09:38 tez Exp $

Fix many temporary file handling issues, including in pdfroff
(resolves CVE-2009-5044 / SA44999)
Patches copied from:
 http://cvsweb.openwall.com/cgi/cvsweb.cgi/Owl/packages/groff/groff-1.20.1-owl-tmp.diff?rev=1.2
Modified for pkgsrc and excluded a documentaion change to doc/groff.texinfo
that changes a `makeinfo' is too old warning into a fatal error.

--- contrib/groffer/perl/groffer.pl.orig	2009-01-09 14:25:52.000000000 +0000
+++ contrib/groffer/perl/groffer.pl
@@ -1380,7 +1380,7 @@ sub _check_prog_on_list {
 ########################################################################
 
 sub main_temp {
-  my $template = 'groffer_' . "$$" . '_XXXX';
+  my $template = 'groffer_' . "$$" . '_XXXXXXXXXX';
   foreach ($ENV{'GROFF_TMPDIR'}, $ENV{'TMPDIR'}, $ENV{'TMP'}, $ENV{'TEMP'},
 	   $ENV{'TEMPDIR'}, File::Spec->catfile($ENV{'HOME'}, 'tmp')) {
     if ($_ && -d $_ && -w $_) {
@@ -1411,12 +1411,12 @@ sub main_temp {
 
   # further argument: SUFFIX => '.sh'
   if ($Debug{'KEEP'}) {
-    ($fh_cat, $tmp_cat) = tempfile(',cat_XXXX', DIR => $tmpdir);
-    ($fh_stdin, $tmp_stdin) = tempfile(',stdin_XXXX', DIR => $tmpdir);
+    ($fh_cat, $tmp_cat) = tempfile(',cat_XXXXXXXXXX', DIR => $tmpdir);
+    ($fh_stdin, $tmp_stdin) = tempfile(',stdin_XXXXXXXXXX', DIR => $tmpdir);
   } else {
-    ($fh_cat, $tmp_cat) = tempfile(',cat_XXXX', UNLINK => 1,
+    ($fh_cat, $tmp_cat) = tempfile(',cat_XXXXXXXXXX', UNLINK => 1,
 				   DIR => $tmpdir);
-    ($fh_stdin, $tmp_stdin) = tempfile(',stdin_XXXX', UNLINK => 1,
+    ($fh_stdin, $tmp_stdin) = tempfile(',stdin_XXXXXXXXXX', UNLINK => 1,
 				       DIR => $tmpdir);
   }
 }				# main_temp()
