$NetBSD: patch-lib_quickml_mail.rb,v 1.1 2012/08/11 13:51:20 obache Exp $

* specify character coding system with ruby-1.9 way

--- lib/quickml/mail.rb.orig	2004-06-07 08:50:59.000000000 +0000
+++ lib/quickml/mail.rb
@@ -1,3 +1,4 @@
+#coding: euc-jp
 #
 # quickml/mail - a part of quickml server
 #
