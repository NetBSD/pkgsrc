$NetBSD: patch-scripts_pkg_pkg.m,v 1.1 2012/10/27 13:01:35 asau Exp $

Provide path to GNU make, since this is what assumed here.

--- scripts/pkg/pkg.m.orig	2012-03-09 21:20:48.000000000 +0000
+++ scripts/pkg/pkg.m
@@ -1379,7 +1379,8 @@ function configure_make (desc, packdir, 
 
     ## Make.
     if (exist (fullfile (src, "Makefile"), "file"))
-      [status, output] = shell (cstrcat (scenv, "make -C '", src, "'"));
+      make = "@GMAKE@"
+      [status, output] = shell (cstrcat (scenv, make, " -C '", src, "'"));
       if (status != 0)
         rm_rf (desc.dir);
         error ("'make' returned the following error: %s", output);
