$NetBSD: patch-src_gl_stdio.in.h,v 1.2 2016/09/19 12:33:10 wiz Exp $

Avoid conflict between gets() and std::gets()

--- src/gl/stdio.in.h.orig	2015-10-07 08:19:33.000000000 +0000
+++ src/gl/stdio.in.h
@@ -719,6 +719,7 @@ _GL_WARN_ON_USE (getline, "getline is un
 # endif
 #endif
 
+#if !defined(__cplusplus)
 /* It is very rare that the developer ever has full control of stdin,
    so any use of gets warrants an unconditional warning; besides, C11
    removed it.  */
@@ -726,6 +727,7 @@ _GL_WARN_ON_USE (getline, "getline is un
 #if HAVE_RAW_DECL_GETS && !defined __cplusplus
 _GL_WARN_ON_USE (gets, "gets is a security hole - use fgets instead");
 #endif
+#endif
 
 #if @GNULIB_OBSTACK_PRINTF@ || @GNULIB_OBSTACK_PRINTF_POSIX@
 struct obstack;
