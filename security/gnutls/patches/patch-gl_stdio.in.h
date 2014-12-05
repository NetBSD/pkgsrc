$NetBSD: patch-gl_stdio.in.h,v 1.2 2014/12/05 12:25:42 khorben Exp $

Avoid conflict between gets() and std::gets()

--- gl/stdio.in.h.orig	2014-04-18 17:03:19.000000000 +0000
+++ gl/stdio.in.h
@@ -714,6 +714,7 @@ _GL_WARN_ON_USE (getline, "getline is un
 # endif
 #endif
 
+#if !(defined __cplusplus)
 /* It is very rare that the developer ever has full control of stdin,
    so any use of gets warrants an unconditional warning; besides, C11
    removed it.  */
@@ -721,6 +722,7 @@ _GL_WARN_ON_USE (getline, "getline is un
 #if HAVE_RAW_DECL_GETS
 _GL_WARN_ON_USE (gets, "gets is a security hole - use fgets instead");
 #endif
+#endif
 
 
 #if @GNULIB_OBSTACK_PRINTF@ || @GNULIB_OBSTACK_PRINTF_POSIX@
