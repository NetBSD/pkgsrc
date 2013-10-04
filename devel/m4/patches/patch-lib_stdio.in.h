$NetBSD: patch-lib_stdio.in.h,v 1.3 2013/10/04 21:02:11 wiz Exp $

glibc 2.16's /usr/include/stdio.h does not provide gets(3) anymore,
and this line causes breakage.
From: http://sources.gentoo.org/cgi-bin/viewvc.cgi/gentoo-x86/sys-devel/m4/files/m4-1.4.16-no-gets.patch

--- lib/stdio.in.h.orig	2013-09-22 06:22:58.000000000 +0000
+++ lib/stdio.in.h
@@ -719,7 +719,6 @@ _GL_WARN_ON_USE (getline, "getline is un
    removed it.  */
 #undef gets
 #if HAVE_RAW_DECL_GETS
-_GL_WARN_ON_USE (gets, "gets is a security hole - use fgets instead");
 #endif
 
 
