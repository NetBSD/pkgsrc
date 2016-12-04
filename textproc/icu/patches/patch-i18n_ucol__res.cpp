$NetBSD: patch-i18n_ucol__res.cpp,v 1.1 2016/12/04 04:11:33 ryoon Exp $

--- i18n/ucol_res.cpp.orig	2016-09-28 02:26:02.000000000 +0000
+++ i18n/ucol_res.cpp
@@ -680,6 +680,7 @@ ucol_getKeywordValuesForLocale(const cha
         return NULL;
     }
     memcpy(en, &defaultKeywordValues, sizeof(UEnumeration));
+    ulist_resetList(sink.values);  // Initialize the iterator.
     en->context = sink.values;
     sink.values = NULL;  // Avoid deletion in the sink destructor.
     return en;
