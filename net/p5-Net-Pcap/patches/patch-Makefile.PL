$NetBSD: patch-Makefile.PL,v 1.2 2014/07/14 11:59:02 jperkin Exp $

Do not override CCFLAGS and LIBS.

--- Makefile.PL.orig	2007-12-23 23:06:15.000000000 +0000
+++ Makefile.PL
@@ -22,8 +22,8 @@ elsif ($^O eq 'cygwin') {
     cygwin_pcap_headers();
 }
 else {
-    $options{CCFLAGS} = '-Wall -Wwrite-strings' if $Config{ccname} eq 'gcc' and $] >= 5.006;
-    $options{LIBS}    = '-lpcap';
+    $options{CCFLAGS} = "$Config{ccflags} -Wall -Wwrite-strings" if $Config{ccname} eq 'gcc' and $] >= 5.006;
+    $options{LIBS}    = "$Config{libs} -lpcap";
 }
 
 for my $arg (@ARGV) {
@@ -530,7 +530,7 @@ sub have_functions {
     my @funcs = ();
     print "detecting available functions... ";
 
-    my @paths = DynaLoader::dl_findfile(qw(-lpcap));
+    my @paths = DynaLoader::dl_findfile(qw(-L@PCAP_LIBDIR@ -lpcap));
     my $libref = DynaLoader::dl_load_file($paths[0]);
 
     for my $func (@_) {
