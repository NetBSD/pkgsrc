$NetBSD: patch-ext_json_parser_parser.rl,v 1.1 2013/02/12 13:03:09 taca Exp $

Fix for CVE-2013-0269.

--- ext/json/parser/parser.rl.orig	2012-04-16 11:15:31.000000000 +0000
+++ ext/json/parser/parser.rl
@@ -607,6 +607,9 @@ static VALUE convert_encoding(VALUE sour
  *   defaults to true.
  * * *object_class*: Defaults to Hash
  * * *array_class*: Defaults to Array
+ * * *quirks_mode*: Enables quirks_mode for parser, that is for example
+ *   parsing single JSON values instead of documents is possible.
+ *
  */
 static VALUE cParser_initialize(int argc, VALUE *argv, VALUE self)
 {
@@ -657,7 +660,7 @@ static VALUE cParser_initialize(int argc
             if (option_given_p(opts, tmp)) {
                 json->create_additions = RTEST(rb_hash_aref(opts, tmp));
             } else {
-                json->create_additions = 1;
+                json->create_additions = 0;
             }
             tmp = ID2SYM(i_create_id);
             if (option_given_p(opts, tmp)) {
