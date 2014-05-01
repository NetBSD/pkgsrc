$NetBSD: patch-i18npool_Library__collator__data.mk,v 1.1 2014/05/01 00:32:11 ryoon Exp $

* Fix icu53 build
  Partially from http://cgit.freedesktop.org/libreoffice/core/commit/?id=2d843bb104a3091a2ff2c7b4d5655f5fb1393a47

--- i18npool/Library_collator_data.mk.orig	2014-04-08 11:46:25.000000000 +0000
+++ i18npool/Library_collator_data.mk
@@ -7,6 +7,9 @@
 # file, You can obtain one at http://mozilla.org/MPL/2.0/.
 #
 
+i18npool_LCDALL := $(wildcard $(SRCDIR)/i18npool/source/collator/data/*.txt)
+i18npool_LCDTXTS := $(filter-out %/ko_charset.txt, $(i18npool_LCDALL))
+
 $(eval $(call gb_Library_Library,collator_data))
 
 $(eval $(call gb_Library_use_libraries,collator_data,\
@@ -14,7 +17,7 @@ $(eval $(call gb_Library_use_libraries,c
 ))
 
 $(eval $(call gb_Library_add_generated_exception_objects,collator_data,\
-	$(foreach txt,$(wildcard $(SRCDIR)/i18npool/source/collator/data/*.txt),\
+	$(foreach txt,$(i18npool_LCDTXTS),\
 		CustomTarget/i18npool/collator/collator_$(notdir $(basename $(txt)))) \
 ))
 
