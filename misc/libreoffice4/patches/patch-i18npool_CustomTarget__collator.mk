$NetBSD: patch-i18npool_CustomTarget__collator.mk,v 1.1 2014/05/01 00:32:11 ryoon Exp $

* Fix icu 53 build
  The concept is from http://cgit.freedesktop.org/libreoffice/core/commit/?id=2d843bb104a3091a2ff2c7b4d5655f5fb1393a47

--- i18npool/CustomTarget_collator.mk.orig	2014-04-08 11:46:25.000000000 +0000
+++ i18npool/CustomTarget_collator.mk
@@ -17,7 +17,6 @@ i18npool_COTXTS := \
     ja_charset.txt \
     ja_phonetic_alphanumeric_first.txt \
     ja_phonetic_alphanumeric_last.txt \
-    ko_charset.txt \
     ku_alphanumeric.txt \
     ln_charset.txt \
     my_dictionary.txt \
