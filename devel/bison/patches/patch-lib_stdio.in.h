$NetBSD: patch-lib_stdio.in.h,v 1.1 2015/06/30 21:39:09 richard Exp $
avoid warnings w.r.t. gets() when c++ is used

--- lib/stdio.in.h.orig	2015-01-15 08:25:52.000000000 +0000
+++ lib/stdio.in.h
@@ -723,7 +723,7 @@ _GL_WARN_ON_USE (getline, "getline is un
    so any use of gets warrants an unconditional warning; besides, C11
    removed it.  */
 #undef gets
-#if HAVE_RAW_DECL_GETS
+#if HAVE_RAW_DECL_GETS && !defined(__cplusplus)
 _GL_WARN_ON_USE (gets, "gets is a security hole - use fgets instead");
 #endif
 
