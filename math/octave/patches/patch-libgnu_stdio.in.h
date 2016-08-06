$NetBSD: patch-libgnu_stdio.in.h,v 1.3 2016/08/06 13:03:35 prlw1 Exp $

Do not re-define gets() on SunOS, incompatible prototype.

--- libgnu/stdio.in.h.orig	2016-07-01 18:43:45.000000000 +0000
+++ libgnu/stdio.in.h
@@ -722,10 +722,12 @@ _GL_WARN_ON_USE (getline, "getline is un
 /* It is very rare that the developer ever has full control of stdin,
    so any use of gets warrants an unconditional warning; besides, C11
    removed it.  */
+#ifndef __sun
 #undef gets
 #if HAVE_RAW_DECL_GETS && !defined __cplusplus
 _GL_WARN_ON_USE (gets, "gets is a security hole - use fgets instead");
 #endif
+#endif
 
 #if @GNULIB_OBSTACK_PRINTF@ || @GNULIB_OBSTACK_PRINTF_POSIX@
 struct obstack;
