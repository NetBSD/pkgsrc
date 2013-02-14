$NetBSD: patch-ext_json_parser_parser.c,v 1.1.2.2 2013/02/14 14:58:51 tron Exp $

Fix for CVE-2013-0269.

--- ext/json/parser/parser.c.orig	2012-04-16 11:15:31.000000000 +0000
+++ ext/json/parser/parser.c
@@ -1676,7 +1676,7 @@ static VALUE cParser_initialize(int argc
             if (option_given_p(opts, tmp)) {
                 json->create_additions = RTEST(rb_hash_aref(opts, tmp));
             } else {
-                json->create_additions = 1;
+                json->create_additions = 0;
             }
             tmp = ID2SYM(i_create_id);
             if (option_given_p(opts, tmp)) {
