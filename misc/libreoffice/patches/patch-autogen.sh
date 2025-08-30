$NetBSD: patch-autogen.sh,v 1.6 2025/08/30 06:44:05 ryoon Exp $

* Run configure script with bash

--- autogen.sh.orig	2025-08-12 11:36:36.000000000 +0000
+++ autogen.sh
@@ -335,7 +335,7 @@ if (defined $ENV{NOCONFIGURE}) {
         $ENV{"PROGRAMFILESX86"} = $ENV{"ProgramFiles(x86)"};
     }
 
-    system (@args) && die "Error running configure";
+    system ('@BASH@', @args) && die "Error running configure";
 }
 
 # cspell:ignore Distros PROGRAMFILESX WSLENV emconfigure realpath wslsys
