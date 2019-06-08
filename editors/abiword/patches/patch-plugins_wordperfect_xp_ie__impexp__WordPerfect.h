$NetBSD: patch-plugins_wordperfect_xp_ie__impexp__WordPerfect.h,v 1.2 2019/06/08 10:40:53 rillig Exp $

* adapt wordperfect plugins to dependecies available in pkgsrc 
  from abiword svn date 2014-12-27

--- plugins/wordperfect/xp/ie_impexp_WordPerfect.h.orig	2013-04-07 13:53:03.000000000 +0000
+++ plugins/wordperfect/xp/ie_impexp_WordPerfect.h
@@ -24,7 +24,6 @@
  */
 
 #include "ie_imp_WordPerfect.h"
-#include "ie_exp_WordPerfect.h"
 #include "xap_Module.h"
 
 #define IE_MIMETYPE_WP_51			"application/wordperfect5.1"
