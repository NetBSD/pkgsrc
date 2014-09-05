$NetBSD: patch-lib_gettext_mo.rb,v 1.1 2014/09/05 12:10:43 obache Exp $

* Fix wrong msgid encoding
  https://github.com/ruby-gettext/gettext/commit/3e79bcfda815d9a2711860554f15d6d628665026

--- lib/gettext/mo.rb.orig	2014-09-05 11:50:15.000000000 +0000
+++ lib/gettext/mo.rb
@@ -55,6 +55,7 @@ module GetText
       @filename = nil
       @last_modified = nil
       @little_endian = true
+      @charset = nil
       @output_charset = output_charset
       @plural_proc = nil
       super()
@@ -157,7 +158,8 @@ module GetText
             msgstr = convert_encoding(msgstr, msgid)
           end
         end
-        self[convert_encoding(msgid, msgid)] = msgstr.freeze
+        msgid.force_encoding(@charset) if @charset
+        self[msgid] = msgstr.freeze
       end
       self
     end
