$NetBSD: patch-i18npool_inc_collator_unicode.hxx,v 1.1 2018/04/19 18:07:03 mrg Exp $

add missing ICU namespace needed for icu 61.

--- i18npool/inc/collator_unicode.hxx.orig	2018-03-29 08:04:09.000000000 -0700
+++ i18npool/inc/collator_unicode.hxx	2018-04-18 00:55:50.988337602 -0700
@@ -63,7 +63,7 @@
 
 private:
     const sal_Char *implementationName;
-    RuleBasedCollator *uca_base, *collator;
+    U_ICU_NAMESPACE::RuleBasedCollator *uca_base, *collator;
 #ifndef DISABLE_DYNLOADING
     oslModule hModule;
 #endif
