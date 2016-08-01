$NetBSD: patch-Makefile.PL,v 1.4 2016/08/01 12:34:11 mef Exp $

Do not override CCFLAGS and LIBS.

--- Makefile.PL.orig	2016-05-10 06:23:13.000000000 +0900
+++ Makefile.PL	2016-08-01 21:21:19.000000000 +0900
@@ -24,7 +24,7 @@ elsif ($^O eq 'cygwin') {
 else {
     $options{CCFLAGS} = "$Config{ccflags} -Wall -Wwrite-strings"
         if $Config{ccname} eq "gcc" and $] >= 5.006;
-    $options{LIBS}    = '-lpcap';
+    $options{LIBS}    = "$Config{libs} -lpcap";
 }
 
 for my $arg (@ARGV) {
@@ -537,7 +537,7 @@ sub have_functions {
     my @funcs = ();
     print "detecting available functions... ";
 
-    my @paths = DynaLoader::dl_findfile(qw(-lpcap));
+    my @paths = DynaLoader::dl_findfile(qw(-L@PCAP_LIBDIR@ -lpcap));
     my $libref = DynaLoader::dl_load_file($paths[0]);
 
     for my $func (@_) {
