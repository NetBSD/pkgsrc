$NetBSD: patch-srclib_stdio.in.h,v 1.2 2014/01/01 15:50:01 schmonz Exp $

* Fix build on glibc>=2.16
  From http://www.itkb.ro/kb/linux/patch-libiconv-pentru-glibc-216

--- srclib/stdio.in.h.orig	2011-08-07 13:42:06.000000000 +0000
+++ srclib/stdio.in.h
@@ -695,7 +695,11 @@ _GL_CXXALIASWARN (gets);
 /* It is very rare that the developer ever has full control of stdin,
    so any use of gets warrants an unconditional warning.  Assume it is
    always declared, since it is required by C89.  */
+#if defined(__GLIBC__) && !defined(__UCLIBC__)
+# if !__GLIBC_PREREQ(2, 16)
 _GL_WARN_ON_USE (gets, "gets is a security hole - use fgets instead");
+# endif
+#endif
 #endif
 
 
