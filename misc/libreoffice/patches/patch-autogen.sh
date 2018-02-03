$NetBSD: patch-autogen.sh,v 1.2 2018/02/03 00:39:50 ryoon Exp $

* Run configure script with bash

--- autogen.sh.orig	2018-01-24 20:31:03.000000000 +0000
+++ autogen.sh
@@ -290,7 +290,7 @@ if (defined $ENV{NOCONFIGURE}) {
     push @args, "--enable-option-checking=$option_checking";
 
     print "Running ./configure with '" . join (" ", @args), "'\n";
-    system ("./configure", @args) && die "Error running configure";
+    system ("@BASH@", "./configure", @args) && die "Error running configure";
 }
 
 # Local Variables:
