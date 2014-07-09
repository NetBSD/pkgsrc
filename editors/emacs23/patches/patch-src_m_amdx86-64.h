$NetBSD: patch-src_m_amdx86-64.h,v 1.2 2014/07/09 03:18:44 taca Exp $

Add support for DragonFly.

--- src/m/amdx86-64.h.orig	2011-11-26 03:20:20.000000000 +0000
+++ src/m/amdx86-64.h
@@ -101,6 +101,10 @@ along with GNU Emacs.  If not, see <http
 
 /* LIB_STANDARD and START_FILES set correctly in s/netbsd.h */
 
+#elif defined(__DragonFly__)
+
+/* LIB_STANDARD and START_FILES set correctly in s/dragonfly.h */
+
 #elif defined(SOLARIS2)
 
 #undef START_FILES
