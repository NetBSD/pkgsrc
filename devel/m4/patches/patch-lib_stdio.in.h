$NetBSD: patch-lib_stdio.in.h,v 1.2 2013/07/19 14:49:28 ryoon Exp $

glibc 2.16's /usr/include/stdio.h does not provide gets(3) anymore,
and this line causes breakage.
From: http://sources.gentoo.org/cgi-bin/viewvc.cgi/gentoo-x86/sys-devel/m4/files/m4-1.4.16-no-gets.patch

--- lib/stdio.in.h.orig	2011-03-01 16:39:29.000000000 +0000
+++ lib/stdio.in.h
@@ -162,7 +162,6 @@ _GL_WARN_ON_USE (fflush, "fflush is not 
    so any use of gets warrants an unconditional warning.  Assume it is
    always declared, since it is required by C89.  */
 #undef gets
-_GL_WARN_ON_USE (gets, "gets is a security hole - use fgets instead");
 
 #if @GNULIB_FOPEN@
 # if @REPLACE_FOPEN@
