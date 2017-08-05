$NetBSD: patch-dbm_include_cdefs.h,v 1.1 2017/08/05 09:39:01 maya Exp $

Don't redefine __BEGIN_DECLS
Match GCC minimum version check to comment (don't spuriously apply to modern
compilers)

--- dbm/include/cdefs.h.orig	2012-03-06 14:45:25.000000000 +0000
+++ dbm/include/cdefs.h
@@ -38,6 +38,7 @@
 #ifndef	_CDEFS_H_
 #define	_CDEFS_H_
 
+#ifndef __BEGIN_DECLS
 #if defined(__cplusplus)
 #define	__BEGIN_DECLS	extern "C" {
 #define	__END_DECLS	}
@@ -45,6 +46,7 @@
 #define	__BEGIN_DECLS
 #define	__END_DECLS
 #endif
+#endif
 
 /*
  * The __CONCAT macro is used to concatenate parts of symbol names, e.g.
@@ -109,7 +111,7 @@
  * these work for GNU C++ (modulo a slight glitch in the C++ grammar
  * in the distribution version of 2.5.5).
  */
-#if !defined(__GNUC__) || __GNUC__ < 2 || __GNUC_MINOR__ < 5
+#if !defined(__GNUC__) || (__GNUC__ < 2 && __GNUC_MINOR__ < 5)
 #define	__attribute__(x)	/* delete __attribute__ if non-gcc or gcc1 */
 #if defined(__GNUC__) && !defined(__STRICT_ANSI__)
 #define	__dead		__volatile
