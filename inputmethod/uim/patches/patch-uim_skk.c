$NetBSD: patch-uim_skk.c,v 1.1 2023/02/25 17:42:43 ryoon Exp $

--- uim/skk.c.orig	2017-08-14 00:07:27.000000000 +0000
+++ uim/skk.c
@@ -1582,6 +1582,7 @@ skk_merge_replaced_numeric_str(uim_lisp 
       numlst_ = CDR(numlst_);
     }
   }
+  str[newlen] = '\0';
 
   return MAKE_STR_DIRECTLY(str);
 }
