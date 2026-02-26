$NetBSD: patch-libgnu_stdio.in.h,v 1.6 2026/02/26 15:45:32 adam Exp $

Do not re-define gets() on SunOS, incompatible prototype.

--- libgnu/stdio.in.h.orig	2026-02-18 17:54:40.000000000 +0000
+++ libgnu/stdio.in.h
@@ -1132,9 +1132,11 @@ _GL_WARN_ON_USE (getline, "getline is un
 /* It is very rare that the developer ever has full control of stdin,
    so any use of gets warrants an unconditional warning; besides, C11
    removed it.  */
+#ifndef __sun
 #if HAVE_RAW_DECL_GETS && !defined __cplusplus
 _GL_WARN_ON_USE (gets, "gets is a security hole - use fgets instead");
 #endif
+#endif
 
 #if @GNULIB_MDA_GETW@
 /* On native Windows, map 'getw' to '_getw', so that -loldnames is not
