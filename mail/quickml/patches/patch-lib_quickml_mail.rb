$NetBSD: patch-lib_quickml_mail.rb,v 1.2 2013/09/26 09:42:23 obache Exp $

* specify character coding system with ruby-1.9 way
* to_a has been removed from the String

--- lib/quickml/mail.rb.orig	2004-06-07 08:50:59.000000000 +0000
+++ lib/quickml/mail.rb
@@ -1,3 +1,4 @@
+#coding: euc-jp
 #
 # quickml/mail - a part of quickml server
 #
@@ -284,7 +285,7 @@ module QuickML
       def encode_field (field)
 	field.toeuc.gsub(/[¡¡-ô¤]\S*\s*/) {|x|
 	  x.scan(/.{1,10}/).map {|y|
-	    "=?iso-2022-jp?B?" + y.tojis.to_a.pack('m').chomp + "?="
+	    "=?iso-2022-jp?B?" + [y.tojis].pack('m').chomp + "?="
 	  }.join("\n ")
 	}
       end
