$NetBSD: patch-Makefile.PL,v 1.1 2014/01/10 15:40:28 jperkin Exp $

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
