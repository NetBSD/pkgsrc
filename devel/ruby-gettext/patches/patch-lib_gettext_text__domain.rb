$NetBSD: patch-lib_gettext_text__domain.rb,v 1.1 2014/09/05 12:10:43 obache Exp $

* Make plural msgid handling more robust against encoding
  https://github.com/ruby-gettext/gettext/commit/9fb2356971df4ebf9421e18dc38bb770f6357641

--- lib/gettext/text_domain.rb.orig	2014-09-05 11:50:15.000000000 +0000
+++ lib/gettext/text_domain.rb
@@ -95,12 +95,12 @@ module GetText
           end
         end
       else
-        msgid_prefix_re = /^#{Regexp.quote(msgid)}\000/
+        plural_msgid_prefix = "#{msgid}\000"
         mo.each do |key, val|
-          if msgid_prefix_re =~ key
-            ret = val.split("\000")[0]
-            break
-          end
+          next unless Encoding.compatible?(key, plural_msgid_prefix)
+          next unless key.start_with?(plural_msgid_prefix)
+          ret = val.split("\000")[0]
+          break
         end
       end
       ret
