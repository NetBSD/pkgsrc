$NetBSD: patch-autogen.sh,v 1.1 2017/02/04 01:48:00 ryoon Exp $

* Run configure script with bash

--- autogen.sh.orig	2017-01-26 22:22:46.000000000 +0000
+++ autogen.sh
@@ -278,7 +278,7 @@ if (defined $ENV{NOCONFIGURE}) {
     push @args, "--enable-option-checking=$option_checking";
 
     print "Running ./configure with '" . join (" ", @args), "'\n";
-    system ("./configure", @args) && die "Error running configure";
+    system ("@BASH@", "./configure", @args) && die "Error running configure";
 }
 
 # Local Variables:
