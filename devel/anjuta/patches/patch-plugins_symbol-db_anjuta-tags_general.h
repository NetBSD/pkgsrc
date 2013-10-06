$NetBSD: patch-plugins_symbol-db_anjuta-tags_general.h,v 1.1 2013/10/06 20:01:27 joerg Exp $

--- plugins/symbol-db/anjuta-tags/general.h.orig	2013-09-29 15:16:04.000000000 +0000
+++ plugins/symbol-db/anjuta-tags/general.h
@@ -57,10 +57,8 @@
  *  to prevent warnings about unused variables.
  */
 #if (__GNUC__ > 2  ||  (__GNUC__ == 2  &&  __GNUC_MINOR__ >= 7)) && !defined (__GNUG__)
-# define __unused__  __attribute__((unused))
 # define __printf__(s,f)  __attribute__((format (printf, s, f)))
 #else
-# define __unused__
 # define __printf__(s,f)
 #endif
 
