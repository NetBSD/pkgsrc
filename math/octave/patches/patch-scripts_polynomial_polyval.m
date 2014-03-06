$NetBSD: patch-scripts_polynomial_polyval.m,v 1.1 2014/03/06 23:06:58 jperkin Exp $

Texinfo 5.x compatibility.

--- scripts/polynomial/polyval.m.orig	2013-02-21 20:19:24.000000000 +0000
+++ scripts/polynomial/polyval.m
@@ -19,19 +19,21 @@
 ## -*- texinfo -*-
 ## @deftypefn  {Function File} {@var{y} =} polyval (@var{p}, @var{x})
 ## @deftypefnx {Function File} {@var{y} =} polyval (@var{p}, @var{x}, [], @var{mu})
+## @deftypefnx {Function File} {[@var{y}, @var{dy}] =} polyval (@var{p}, @var{x}, @var{s})
+## @deftypefnx {Function File} {[@var{y}, @var{dy}] =} polyval (@var{p}, @var{x}, @var{s}, @var{mu})
+## 
 ## Evaluate the polynomial @var{p} at the specified values of @var{x}.  When
 ## @var{mu} is present, evaluate the polynomial for
 ## (@var{x}-@var{mu}(1))/@var{mu}(2).
 ## If @var{x} is a vector or matrix, the polynomial is evaluated for each of
 ## the elements of @var{x}.
 ## 
-## @deftypefnx {Function File} {[@var{y}, @var{dy}] =} polyval (@var{p}, @var{x}, @var{s})
-## @deftypefnx {Function File} {[@var{y}, @var{dy}] =} polyval (@var{p}, @var{x}, @var{s}, @var{mu})
 ## In addition to evaluating the polynomial, the second output
 ## represents the prediction interval, @var{y} +/- @var{dy}, which
 ## contains at least 50% of the future predictions.  To calculate the
 ## prediction interval, the structured variable @var{s}, originating
 ## from @code{polyfit}, must be supplied.
+## 
 ## @seealso{polyvalm, polyaffine, polyfit, roots, poly}
 ## @end deftypefn
 
