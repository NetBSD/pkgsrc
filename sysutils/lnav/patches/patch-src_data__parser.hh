$NetBSD: patch-src_data__parser.hh,v 1.1 2015/09/05 22:12:04 wiz Exp $

Remove unused variables.

--- src/data_parser.hh.orig	2015-03-31 13:30:23.000000000 +0000
+++ src/data_parser.hh
@@ -437,8 +437,6 @@ private:
             }
 
             if (iter->e_token == this->dp_format->df_terminator) {
-                std::vector<element> key_copy;
-
                 value.SPLICE(value.end(),
                              key_comps,
                              key_comps.begin(),
@@ -480,8 +478,6 @@ private:
                     }
                     else if (key_iter->e_token ==
                              this->dp_format->df_terminator) {
-                        std::vector<element> key_copy;
-
                         value.SPLICE(value.end(),
                                      key_comps,
                                      key_comps.begin(),
