$NetBSD: patch-lib_matplotlib_tri___tri.h,v 1.1 2014/02/26 10:36:58 wiedi Exp $

Rename C++ variables to avoid use of reserved identifiers
See: https://github.com/matplotlib/matplotlib/issues/2463
--- lib/matplotlib/tri/_tri.h.orig	2013-10-10 12:42:48.000000000 +0000
+++ lib/matplotlib/tri/_tri.h
@@ -818,7 +818,7 @@ public:
     unsigned long operator()(unsigned long max_value);
 
 private:
-    const unsigned long _M, _A, _C;
+    const unsigned long _m, _a, _c;
     unsigned long _seed;
 };
 
