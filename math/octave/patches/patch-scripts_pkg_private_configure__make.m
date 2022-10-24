$NetBSD: patch-scripts_pkg_private_configure__make.m,v 1.2 2022/10/24 18:02:19 adam Exp $

Provide path to GNU make, since this is what assumed here.

--- scripts/pkg/private/configure_make.m.orig	2022-07-28 13:08:26.000000000 +0000
+++ scripts/pkg/private/configure_make.m
@@ -110,7 +110,7 @@ function configure_make (desc, packdir, 
     endif
 
     if (exist (fullfile (src, "Makefile"), "file"))
-      [status, output] = shell (sprintf ("%s make --jobs %i --directory '%s'",
+      [status, output] = shell (sprintf ("%s @GMAKE@ --jobs %i --directory '%s'",
                                          scenv, jobs, src), verbose);
       if (status != 0)
         disp (output);
