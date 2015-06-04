$NetBSD: patch-src_gl_stdio.in.h,v 1.1 2015/06/04 09:43:53 jperkin Exp $

Avoid conflict between gets() and std::gets()

--- src/gl/stdio.in.h.orig	2015-03-23 20:57:21.000000000 +0000
+++ src/gl/stdio.in.h
@@ -714,6 +714,7 @@ _GL_WARN_ON_USE (getline, "getline is un
 # endif
 #endif
 
+#if !defined(__cplusplus)
 /* It is very rare that the developer ever has full control of stdin,
    so any use of gets warrants an unconditional warning; besides, C11
    removed it.  */
@@ -721,6 +722,7 @@ _GL_WARN_ON_USE (getline, "getline is un
 #if HAVE_RAW_DECL_GETS
 _GL_WARN_ON_USE (gets, "gets is a security hole - use fgets instead");
 #endif
+#endif
 
 
 #if @GNULIB_OBSTACK_PRINTF@ || @GNULIB_OBSTACK_PRINTF_POSIX@
