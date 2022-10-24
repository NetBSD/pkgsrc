$NetBSD: patch-libgnu_stdio.in.h,v 1.5 2022/10/24 18:02:19 adam Exp $

Do not re-define gets() on SunOS, incompatible prototype.

--- libgnu/stdio.in.h.orig	2022-07-28 13:08:26.000000000 +0000
+++ libgnu/stdio.in.h
@@ -934,10 +934,12 @@ _GL_WARN_ON_USE (getline, "getline is un
 /* It is very rare that the developer ever has full control of stdin,
    so any use of gets warrants an unconditional warning; besides, C11
    removed it.  */
+#ifndef __sun
 #undef gets
 #if HAVE_RAW_DECL_GETS && !defined __cplusplus
 _GL_WARN_ON_USE (gets, "gets is a security hole - use fgets instead");
 #endif
+#endif
 
 #if @GNULIB_MDA_GETW@
 /* On native Windows, map 'getw' to '_getw', so that -loldnames is not
