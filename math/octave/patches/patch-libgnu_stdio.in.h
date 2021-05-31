$NetBSD: patch-libgnu_stdio.in.h,v 1.4 2021/05/31 07:16:51 thor Exp $

Do not re-define gets() on SunOS, incompatible prototype.

--- libgnu/stdio.in.h.orig	2021-02-19 17:36:34.000000000 +0000
+++ libgnu/stdio.in.h
@@ -838,10 +838,12 @@ _GL_WARN_ON_USE (getline, "getline is un
 /* It is very rare that the developer ever has full control of stdin,
    so any use of gets warrants an unconditional warning; besides, C11
    removed it.  */
+#ifndef __sun
 #undef gets
 #if HAVE_RAW_DECL_GETS && !defined __cplusplus
 _GL_WARN_ON_USE (gets, "gets is a security hole - use fgets instead");
 #endif
+#endif
 
 #if defined _WIN32 && !defined __CYGWIN__
 # undef getw
