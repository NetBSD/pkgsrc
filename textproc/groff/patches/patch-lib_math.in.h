$NetBSD: patch-lib_math.in.h,v 1.1 2025/05/08 05:29:47 dbj Exp $

Header file fix with libc++ taken from
https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=240701
Actual upstream fix is more invasive:
https://savannah.gnu.org/bugs/?64910
Fixes build on Darwin

--- lib/math.in.h.orig	2023-07-05 20:58:27.000000000 +0000
+++ lib/math.in.h
@@ -54,7 +54,7 @@
 #endif
 
 #ifndef _GL_INLINE_HEADER_BEGIN
- #error "Please include config.h first."
+ #include "config.h"
 #endif
 _GL_INLINE_HEADER_BEGIN
 #ifndef _GL_MATH_INLINE
