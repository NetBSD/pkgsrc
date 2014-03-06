$NetBSD: patch-scripts_miscellaneous_license.m,v 1.1 2014/03/06 23:06:58 jperkin Exp $

Texinfo 5.x compatibility.

--- scripts/miscellaneous/license.m.orig	2013-02-21 20:19:24.000000000 +0000
+++ scripts/miscellaneous/license.m
@@ -18,20 +18,26 @@
 
 ## -*- texinfo -*-
 ## @deftypefn {Function File} {} license
+## @deftypefnx {Function File} {} license ("inuse")
+## @deftypefnx {Function File} {@var{retval} =} license ("inuse")
+## @deftypefnx {Function File} {@var{retval} =} license ("test", @var{feature})
+## @deftypefnx {Function File} {} license ("test", @var{feature}, @var{toggle})
+## @deftypefnx {Function File} {@var{retval} =} license ("checkout", @var{feature})
+## 
 ## Display the license of Octave.
 ##
-## @deftypefnx {Function File} {} license ("inuse")
+## @code{license ("inuse")}
 ## Display a list of packages currently being used.
 ##
-## @deftypefnx {Function File} {@var{retval} =} license ("inuse")
+## @code{@var{retval} = license ("inuse")}
 ## Return a structure containing the fields @code{feature} and @code{user}.
 ##
-## @deftypefnx {Function File} {@var{retval} =} license ("test", @var{feature})
+## @code{@var{retval} = license ("test", @var{feature})}
 ## Return 1 if a license exists for the product identified by the string
 ## @var{feature} and 0 otherwise.  The argument @var{feature} is case
 ## insensitive and only the first 27 characters are checked.
 ##
-## @deftypefnx {Function File} {} license ("test", @var{feature}, @var{toggle})
+## @code{license ("test", @var{feature}, @var{toggle})}
 ## Enable or disable license testing for @var{feature}, depending on
 ## @var{toggle}, which may be one of:
 ##
@@ -44,7 +50,7 @@
 ## Future tests for the specified license of @var{feature} return 0.
 ## @end table
 ##
-## @deftypefnx {Function File} {@var{retval} =} license ("checkout", @var{feature})
+## @code{@var{retval} = license ("checkout", @var{feature})}
 ## Check out a license for @var{feature}, returning 1 on success and 0
 ## on failure.
 ##
