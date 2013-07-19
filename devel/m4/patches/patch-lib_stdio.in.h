$NetBSD: patch-lib_stdio.in.h,v 1.1 2013/07/19 12:13:36 ryoon Exp $

From: http://sources.gentoo.org/cgi-bin/viewvc.cgi/gentoo-x86/sys-devel/m4/files/m4-1.4.16-no-gets.patch
Gnulib intentionally does not have a gets module, and now that C11
and glibc have dropped it, we should be more proactive about warning
any user on a platform that still has a declaration of this dangerous
interface.

--- lib/stdio.in.h.orig	2011-03-01 16:39:29.000000000 +0000
+++ lib/stdio.in.h
@@ -162,7 +162,6 @@ _GL_WARN_ON_USE (fflush, "fflush is not 
    so any use of gets warrants an unconditional warning.  Assume it is
    always declared, since it is required by C89.  */
 #undef gets
-_GL_WARN_ON_USE (gets, "gets is a security hole - use fgets instead");
 
 #if @GNULIB_FOPEN@
 # if @REPLACE_FOPEN@
