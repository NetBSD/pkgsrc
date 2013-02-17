$NetBSD: patch-src_m_amdx86-64.h,v 1.1 2013/02/17 04:59:43 dholland Exp $

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
