$NetBSD: patch-lib_stdio.in.h,v 1.4 2017/08/25 05:28:53 adam Exp $

glibc 2.16's /usr/include/stdio.h does not provide gets(3) anymore,
and this line causes breakage.
From: http://sources.gentoo.org/cgi-bin/viewvc.cgi/gentoo-x86/sys-devel/m4/files/m4-1.4.16-no-gets.patch

--- lib/stdio.in.h.orig	2016-12-31 13:54:42.000000000 +0000
+++ lib/stdio.in.h
@@ -744,7 +744,6 @@ _GL_WARN_ON_USE (getline, "getline is un
    removed it.  */
 #undef gets
 #if HAVE_RAW_DECL_GETS && !defined __cplusplus
-_GL_WARN_ON_USE (gets, "gets is a security hole - use fgets instead");
 #endif
 
 #if @GNULIB_OBSTACK_PRINTF@ || @GNULIB_OBSTACK_PRINTF_POSIX@
