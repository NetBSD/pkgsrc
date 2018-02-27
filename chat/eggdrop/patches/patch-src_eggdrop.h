$NetBSD: patch-src_eggdrop.h,v 1.1 2018/02/27 19:08:48 fhajny Exp $

Don't hardcode a relative LANGDIR.

--- src/eggdrop.h.orig	2017-08-13 21:07:00.000000000 +0000
+++ src/eggdrop.h
@@ -62,7 +62,6 @@
 
 
 /* Language stuff */
-#define LANGDIR  "./language" /* language file directory                   */
 #define BASELANG "english"    /* language which always gets loaded before
                                  all other languages. You do not want to
                                  change this.                              */
