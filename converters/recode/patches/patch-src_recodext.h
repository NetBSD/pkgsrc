$NetBSD: patch-src_recodext.h,v 1.1 2011/08/26 08:13:44 wiz Exp $

Fix gcc-4.5 problem:
In file included from common.h:140:0,
                 from charname.c:20:
recodext.h:221:5: error: width of 'ignore' exceeds its type

See also
https://github.com/pinard/Recode/commit/a34dfd2257f412dff59f2ad7f714252fa200028e#src/recodext.h

--- src/recodext.h.orig	2001-01-04 14:36:54.000000000 +0000
+++ src/recodext.h
@@ -218,7 +218,7 @@ struct recode_symbol
     enum recode_symbol_type type : 3;
 
     /* Non zero if this one should be ignored.  */
-    bool ignore : 2;
+    bool ignore : 1;
   };
 
 struct recode_surface_list
