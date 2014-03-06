$NetBSD: patch-scripts_signal_freqz.m,v 1.1 2014/03/06 23:06:58 jperkin Exp $

Texinfo 5.x compatibility.

--- scripts/signal/freqz.m.orig	2013-02-21 20:19:24.000000000 +0000
+++ scripts/signal/freqz.m
@@ -18,6 +18,10 @@
 
 ## -*- texinfo -*-
 ## @deftypefn {Function File} {[@var{h}, @var{w}] =} freqz (@var{b}, @var{a}, @var{n}, "whole")
+## @deftypefnx {Function File} {@var{h} =} freqz (@var{b}, @var{a}, @var{w})
+## @deftypefnx {Function File} {[@dots{}] =} freqz (@dots{}, @var{Fs})
+## @deftypefnx {Function File} {} freqz (@dots{})
+## 
 ## Return the complex frequency response @var{h} of the rational IIR filter
 ## whose numerator and denominator coefficients are @var{b} and @var{a},
 ## respectively.  The response is evaluated at @var{n} angular frequencies
@@ -49,16 +53,16 @@
 ## For fastest computation, @var{n} should factor into a small number of
 ## small primes.
 ##
-## @deftypefnx {Function File} {@var{h} =} freqz (@var{b}, @var{a}, @var{w})
+## @code{freqz (@var{b}, @var{a}, @var{w})}
 ## Evaluate the response at the specific frequencies in the vector @var{w}.
 ## The values for @var{w} are measured in radians.
 ##
-## @deftypefnx {Function File} {[@dots{}] =} freqz (@dots{}, @var{Fs})
+## @code{[@dots{}] = freqz (@dots{}, @var{Fs})}
 ## Return frequencies in Hz instead of radians assuming a sampling rate
 ## @var{Fs}.  If you are evaluating the response at specific frequencies
 ## @var{w}, those frequencies should be requested in Hz rather than radians.
 ##
-## @deftypefnx {Function File} {} freqz (@dots{})
+## @code{freqz (@dots{})}
 ## Plot the pass band, stop band and phase response of @var{h} rather
 ## than returning them.
 ## @end deftypefn
