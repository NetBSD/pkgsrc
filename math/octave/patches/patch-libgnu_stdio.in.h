$NetBSD: patch-libgnu_stdio.in.h,v 1.1 2014/03/06 23:09:04 jperkin Exp $

Do not re-define gets() on SunOS, incompatible prototype.

--- libgnu/stdio.in.h.orig	2013-02-21 20:21:19.000000000 +0000
+++ libgnu/stdio.in.h
@@ -704,10 +704,12 @@ _GL_WARN_ON_USE (getline, "getline is un
 /* It is very rare that the developer ever has full control of stdin,
    so any use of gets warrants an unconditional warning; besides, C11
    removed it.  */
+#ifndef __sun
 #undef gets
 #if HAVE_RAW_DECL_GETS
 _GL_WARN_ON_USE (gets, "gets is a security hole - use fgets instead");
 #endif
+#endif
 
 
 #if @GNULIB_OBSTACK_PRINTF@ || @GNULIB_OBSTACK_PRINTF_POSIX@
