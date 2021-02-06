$NetBSD: patch-autogen.sh,v 1.4 2021/02/06 06:47:24 ryoon Exp $

* Run configure script with bash

--- autogen.sh.orig	2021-01-27 19:33:49.000000000 +0000
+++ autogen.sh
@@ -313,7 +313,7 @@ if (defined $ENV{NOCONFIGURE}) {
         $ENV{"PROGRAMFILESX86"} = $ENV{"ProgramFiles(x86)"};
     }
 
-    system ("./configure", @args) && die "Error running configure";
+    system ("@BASH@", "./configure", @args) && die "Error running configure";
 }
 
 # Local Variables:
