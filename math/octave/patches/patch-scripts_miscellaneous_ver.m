$NetBSD: patch-scripts_miscellaneous_ver.m,v 1.1 2014/03/06 23:06:58 jperkin Exp $

Texinfo 5.x compatibility.

--- scripts/miscellaneous/ver.m.orig	2013-02-21 20:19:24.000000000 +0000
+++ scripts/miscellaneous/ver.m
@@ -18,11 +18,15 @@
 
 ## -*- texinfo -*-
 ## @deftypefn {Function File} {} ver ()
+## @deftypefnx {Function File} {v =} ver ()
+## @deftypefnx {Function File} {v =} ver ("Octave")
+## @deftypefnx {Function File} {v =} ver (@var{package})
+## 
 ## Display a header containing the current Octave version number, license
 ## string and operating system, followed by the installed package names,
 ## versions, and installation directories.
 ##
-## @deftypefnx {Function File} {v =} ver ()
+## @code{v = ver ()}
 ## Return a vector of structures, respecting Octave and each installed package.
 ## The structure includes the following fields.
 ##
@@ -40,10 +44,10 @@
 ## Date respecting the version/revision.
 ## @end table
 ##
-## @deftypefnx {Function File} {v =} ver ("Octave")
+## @code{v = ver ("Octave")}
 ## Return version information for Octave only.
 ##
-## @deftypefnx {Function File} {v =} ver (@var{package})
+## @code{v = ver (@var{package})}
 ## Return version information for @var{package}.
 ##
 ## @seealso{version, octave_config_info}
