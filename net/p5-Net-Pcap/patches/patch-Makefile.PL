$NetBSD: patch-Makefile.PL,v 1.3 2015/02/21 09:43:54 mef Exp $

Do not override CCFLAGS and LIBS.

--- Makefile.PL.orig	2012-11-28 08:06:02.000000000 +0900
+++ Makefile.PL	2015-02-21 18:25:18.000000000 +0900
@@ -22,9 +22,8 @@ elsif ($^O eq 'cygwin') {
     cygwin_pcap_headers();
 }
 else {
-    $options{CCFLAGS} = "-Wall -Wwrite-strings"
-        if $Config{ccname} eq "gcc" and $] >= 5.006;
-    $options{LIBS}    = '-lpcap';
+    $options{CCFLAGS} = "$Config{ccflags} -Wall -Wwrite-strings" if $Config{ccname} eq 'gcc' and $] >= 5.006;
+    $options{LIBS}    = "$Config{libs} -lpcap";
 }
 
 for my $arg (@ARGV) {
@@ -536,7 +535,7 @@ sub have_functions {
     my @funcs = ();
     print "detecting available functions... ";
 
-    my @paths = DynaLoader::dl_findfile(qw(-lpcap));
+    my @paths = DynaLoader::dl_findfile(qw(-L@PCAP_LIBDIR@ -lpcap));
     my $libref = DynaLoader::dl_load_file($paths[0]);
 
     for my $func (@_) {
