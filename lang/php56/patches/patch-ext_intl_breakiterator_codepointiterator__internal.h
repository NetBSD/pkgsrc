$NetBSD: patch-ext_intl_breakiterator_codepointiterator__internal.h,v 1.1 2021/12/09 00:13:07 tnn Exp $

php73-intl: fix icu>=70 fallout. Backport from php74-intl.

--- ext/intl/breakiterator/codepointiterator_internal.h.orig	2019-01-09 09:54:13.000000000 +0000
+++ ext/intl/breakiterator/codepointiterator_internal.h
@@ -36,7 +36,11 @@ namespace PHP {
 
 		virtual ~CodePointBreakIterator();
 
+#if U_ICU_VERSION_MAJOR_NUM >= 70
+		virtual bool operator==(const BreakIterator& that) const;
+#else
 		virtual UBool operator==(const BreakIterator& that) const;
+#endif
 
 		virtual CodePointBreakIterator* clone(void) const;
 
