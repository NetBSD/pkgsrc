$NetBSD: patch-scripts_texi2pod.pl,v 1.1 2013/06/03 11:54:42 obache Exp $

* allow UTF-8 in man
  pod2man in perl-5.18 dislike using UTF-8 character without =encoding
  http://git.qemu.org/?p=qemu.git;a=commitdiff;h=3179d694a8dcaa091131e3db644d445c0130713e

--- scripts/texi2pod.pl.orig	2011-10-12 16:41:43.000000000 +0000
+++ scripts/texi2pod.pl
@@ -36,6 +36,7 @@ $fnno = 1;
 $inf = "";
 $ibase = "";
 @ipath = ();
+$encoding = undef;
 
 while ($_ = shift) {
     if (/^-D(.*)$/) {
@@ -97,6 +98,12 @@ while(<$inf>) {
     /^\@setfilename\s+([^.]+)/ and $fn = $1, next;
     /^\@settitle\s+([^.]+)/ and $tl = postprocess($1), next;
 
+    # Look for document encoding
+    /^\@documentencoding\s+([^.]+)/ and do {
+	$encoding = $1 unless defined $encoding;
+	next;
+    };
+
     # Identify a man title but keep only the one we are interested in.
     /^\@c\s+man\s+title\s+([A-Za-z0-9-]+)\s+(.+)/ and do {
 	if (exists $defs{$1}) {
@@ -336,6 +343,8 @@ $inf = pop @instack;
 
 die "No filename or title\n" unless defined $fn && defined $tl;
 
+print "=encoding $encoding\n\n" if defined $encoding;
+
 $sects{NAME} = "$fn \- $tl\n";
 $sects{FOOTNOTES} .= "=back\n" if exists $sects{FOOTNOTES};
 
