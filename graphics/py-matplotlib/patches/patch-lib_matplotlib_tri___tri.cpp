$NetBSD: patch-lib_matplotlib_tri___tri.cpp,v 1.1 2014/02/26 10:36:58 wiedi Exp $

Rename C++ variables to avoid use of reserved identifiers
See: https://github.com/matplotlib/matplotlib/issues/2463
--- lib/matplotlib/tri/_tri.cpp.orig	2013-10-10 12:42:48.000000000 +0000
+++ lib/matplotlib/tri/_tri.cpp
@@ -2177,14 +2177,14 @@ TrapezoidMapTriFinder::Trapezoid::set_up
 
 
 RandomNumberGenerator::RandomNumberGenerator(unsigned long seed)
-    : _M(21870), _A(1291), _C(4621), _seed(seed % _M)
+    : _m(21870), _a(1291), _c(4621), _seed(seed % _m)
 {}
 
 unsigned long
 RandomNumberGenerator::operator()(unsigned long max_value)
 {
-    _seed = (_seed*_A + _C) % _M;
-    return (_seed*max_value) / _M;
+    _seed = (_seed*_a + _c) % _m;
+    return (_seed*max_value) / _m;
 }
 
 
