$NetBSD: patch-lib_PerlPowerTools.pm,v 1.1 2025/11/30 06:24:16 scole Exp $

Add get_dictionary_path to look for default dictionary

--- lib/PerlPowerTools.pm.orig	2025-11-04 14:05:44.000000000 +0000
+++ lib/PerlPowerTools.pm
@@ -1,6 +1,31 @@
 package PerlPowerTools;
 
 our $VERSION = '1.053';
+
+use strict;
+use warnings;
+use Exporter;
+
+our @ISA= qw ( Exporter );
+
+our @EXPORT = qw( get_dictionary_path );
+
+#
+# return path to existing dictionary file. arg is string path to
+# preferred dictionary.  die if no dictionary found
+#
+sub get_dictionary_path {
+    my $pdict = shift @_;
+
+    my @dicts = qw ( /usr/share/dict/words /usr/dict/words );
+    unshift @dicts, ( $pdict ) if $pdict;
+
+    foreach ( @dicts ) {
+        return $_ if -e $_;
+    }
+    die "unable to open any dictionary from ", join(":", @dicts);
+}
+
 1;
 
 =encoding utf8
