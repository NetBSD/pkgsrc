$NetBSD: patch-help2man.PL,v 1.1 2014/07/15 14:54:52 ryoon Exp $

* SCO OpenServer 5.0.7/3.2's nl_langinfo(3) returns always empty.
  Do not fail with error.

--- help2man.PL.orig	2014-03-24 11:29:43.000000000 +0000
+++ help2man.PL
@@ -124,7 +124,7 @@ my $encoding;
 
     sub dec { $encoding ? decode $encoding, $_[0] : $_[0] }
     sub enc { $encoding ? encode $encoding, $_[0] : $_[0] }
-    sub enc_user { encode $user_encoding, $_[0] }
+    sub enc_user { $user_encoding ? encode $user_encoding, $_[0] : $_[0] }
     sub kark # die with message formatted in the invoking user's locale
     {
 	setlocale LC_ALL, $user_locale;
