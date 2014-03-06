$NetBSD: patch-scripts_set_union.m,v 1.1 2014/03/06 23:06:58 jperkin Exp $

Texinfo 5.x compatibility.

--- scripts/set/union.m.orig	2013-02-21 20:19:24.000000000 +0000
+++ scripts/set/union.m
@@ -20,6 +20,8 @@
 ## -*- texinfo -*-
 ## @deftypefn  {Function File} {} union (@var{a}, @var{b})
 ## @deftypefnx {Function File} {} union (@var{a}, @var{b}, "rows")
+## @deftypefnx {Function File} {[@var{c}, @var{ia}, @var{ib}] =} union (@var{a}, @var{b})
+##
 ## Return the set of elements that are in either of the sets @var{a} and
 ## @var{b}.  @var{a}, @var{b} may be cell arrays of string(s).
 ## For example:
@@ -44,7 +46,6 @@
 ## @end group
 ## @end example
 ##
-## @deftypefnx {Function File} {[@var{c}, @var{ia}, @var{ib}] =} union (@var{a}, @var{b})
 ##
 ## Return index vectors @var{ia} and @var{ib} such that @code{a(ia)} and
 ## @code{b(ib)} are disjoint sets whose union is @var{c}.
