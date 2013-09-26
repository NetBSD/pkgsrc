$NetBSD: patch-lib_quickml_gettext.rb,v 1.2 2013/09/26 09:42:23 obache Exp $

* specify character coding system with ruby-1.9 way
* for the case if the encoding of the code of quickml and encoding specified
  in messages are different

--- lib/quickml/gettext.rb.orig	2004-06-07 08:50:59.000000000 +0000
+++ lib/quickml/gettext.rb
@@ -1,3 +1,4 @@
+#coding: euc-jp
 #
 # quickml/gettext - a part of quickml server
 #
@@ -22,14 +23,14 @@ module QuickML
 
       def gettext (text, *args)
 	unless @catalog && @catalog.charset == @message_charset
-	  return sprintf(text, *args) 
+	  return sprintf(text, *args).force_encoding("ASCII-8BIT")
 	end
 
 	translated_message = @catalog.messages[text]	  
 	if translated_message
-	  codeconv(sprintf(translated_message, *args))
+	  codeconv(sprintf(translated_message, *args)).force_encoding("ASCII-8BIT")
 	else
-	  sprintf(text, *args)
+	  sprintf(text, *args).force_encoding("ASCII-8BIT")
 	end
       end
 
