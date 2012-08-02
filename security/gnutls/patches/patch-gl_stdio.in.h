$NetBSD: patch-gl_stdio.in.h,v 1.1 2012/08/02 09:37:32 jperkin Exp $

Avoid conflict between gets() and std::gets()

--- gl/stdio.in.h.orig	Thu Aug  2 09:29:29 2012
+++ gl/stdio.in.h	Thu Aug  2 09:30:17 2012
@@ -699,6 +699,7 @@
 # endif
 #endif
 
+#if !(defined __cplusplus)
 /* It is very rare that the developer ever has full control of stdin,
    so any use of gets warrants an unconditional warning; besides, C11
    removed it.  */
@@ -706,6 +707,7 @@
 #if HAVE_RAW_DECL_GETS
 _GL_WARN_ON_USE (gets, "gets is a security hole - use fgets instead");
 #endif
+#endif
 
 
 #if @GNULIB_OBSTACK_PRINTF@ || @GNULIB_OBSTACK_PRINTF_POSIX@
