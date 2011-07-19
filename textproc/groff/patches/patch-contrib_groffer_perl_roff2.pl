$NetBSD: patch-contrib_groffer_perl_roff2.pl,v 1.1 2011/07/19 21:09:39 tez Exp $

Fix many temporary file handling issues, including in pdfroff
(resolves CVE-2009-5044 / SA44999)
Patches copied from:
 http://cvsweb.openwall.com/cgi/cvsweb.cgi/Owl/packages/groff/groff-1.20.1-owl-tmp.diff?rev=1.2
Modified for pkgsrc and excluded a documentaion change to doc/groff.texinfo
that changes a `makeinfo' is too old warning into a fatal error.

--- contrib/groffer/perl/roff2.pl.orig	2009-01-09 14:25:52.000000000 +0000
+++ contrib/groffer/perl/roff2.pl
@@ -124,7 +124,7 @@ if ($Has_Groffer) {
 	last;
       }
     }
-    my $template = $Name . '_XXXX';
+    my $template = $Name . '_XXXXXXXXXX';
     my ($fh, $stdin);
     if ($tempdir) {
       ($fh, $stdin) = tempfile($template, UNLINK => 1, DIR => $tempdir) ||
