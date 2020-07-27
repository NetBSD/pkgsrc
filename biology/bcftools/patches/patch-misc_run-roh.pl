$NetBSD: patch-misc_run-roh.pl,v 1.1 2020/07/27 00:29:04 bacon Exp $

# bash path

--- misc/run-roh.pl.orig	2019-12-19 09:57:32.000000000 +0000
+++ misc/run-roh.pl
@@ -110,7 +110,7 @@ sub cmd
 
     if ( $args{verbose} ) { print STDERR $cmd,"\n"; }
 
-    # Why not to use backticks? Perl calls /bin/sh, which is often bash. To get the correct
+    # Why not to use backticks? Perl calls bash, which is often bash. To get the correct
     #   status of failing pipes, it must be called with the pipefail option.
 
     my $kid_io;
@@ -127,7 +127,7 @@ sub cmd
     else 
     {      
         # child
-        exec('/bin/bash', '-o','pipefail','-c', $cmd) or error("Failed to run the command [/bin/sh -o pipefail -c $cmd]: $!");
+        exec('bash', '-c', $cmd) or error("Failed to run the command [bash -c $cmd]: $!");
     }
 
     if ( exists($args{exit_on_error}) && !$args{exit_on_error} ) { return @out; }
