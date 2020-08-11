$NetBSD: patch-autogen.sh,v 1.3 2020/08/11 16:07:39 ryoon Exp $

* Run configure script with bash

--- autogen.sh.orig	2020-07-29 19:29:17.000000000 +0000
+++ autogen.sh
@@ -296,7 +296,7 @@ if (defined $ENV{NOCONFIGURE}) {
     push @args, "--enable-option-checking=$option_checking";
 
     print "Running ./configure with '" . join (" ", @args), "'\n";
-    system ("./configure", @args) && die "Error running configure";
+    system ("@BASH@", "./configure", @args) && die "Error running configure";
 }
 
 # Local Variables:
