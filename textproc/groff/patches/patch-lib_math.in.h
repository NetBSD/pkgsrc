$NetBSD: patch-lib_math.in.h,v 1.2 2026/07/19 08:05:45 adam Exp $

Header file fix with libc++ taken from
https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=240701
Actual upstream fix is more invasive:
https://savannah.gnu.org/bugs/?64910
Fixes build on Darwin

--- lib/math.in.h.orig	2026-03-08 13:32:36.000000000 +0000
+++ lib/math.in.h
@@ -51,7 +51,7 @@
 /* This file uses _GL_INLINE_HEADER_BEGIN, _GL_INLINE, _GL_ATTRIBUTE_CONST,
    GNULIB_POSIXCHECK, HAVE_RAW_DECL_*.  */
 #if !_GL_CONFIG_H_INCLUDED
- #error "Please include config.h first."
+#include "config.h"
 #endif
 
 /* On OpenVMS, NAN, INFINITY, and HUGEVAL macros are defined in <fp.h>.  */
