$NetBSD: patch-lib_stdio.in.h,v 1.1 2013/02/26 14:47:16 jperkin Exp $

Remove broken gets() warning, conflicts with std::gets.

--- lib/stdio.in.h.orig	2011-09-29 09:54:41.000000000 +0000
+++ lib/stdio.in.h
@@ -715,7 +715,6 @@ _GL_CXXALIASWARN (gets);
 /* It is very rare that the developer ever has full control of stdin,
    so any use of gets warrants an unconditional warning.  Assume it is
    always declared, since it is required by C89.  */
-_GL_WARN_ON_USE (gets, "gets is a security hole - use fgets instead");
 #endif
 
 
