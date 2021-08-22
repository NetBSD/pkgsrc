$NetBSD: patch-autogen.sh,v 1.5 2021/08/22 02:41:50 ryoon Exp $

* Run configure script with bash

--- autogen.sh.orig	2021-08-16 19:56:28.000000000 +0000
+++ autogen.sh
@@ -319,7 +319,7 @@ if (defined $ENV{NOCONFIGURE}) {
         $ENV{"PROGRAMFILESX86"} = $ENV{"ProgramFiles(x86)"};
     }
 
-    system (@args) && die "Error running configure";
+    system ('@BASH@', @args) && die "Error running configure";
 }
 
 # Local Variables:
