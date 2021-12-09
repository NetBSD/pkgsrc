$NetBSD: patch-ext_intl_breakiterator_codepointiterator__internal.cpp,v 1.2 2021/12/09 00:13:07 tnn Exp $

php56-intl: fix icu>=70 fallout. Backport from php74-intl.

--- ext/intl/breakiterator/codepointiterator_internal.cpp.orig	2019-01-09 09:54:13.000000000 +0000
+++ ext/intl/breakiterator/codepointiterator_internal.cpp
@@ -55,7 +55,7 @@ CodePointBreakIterator& CodePointBreakIt
 		return *this;
 	}
 
-	this->fText = utext_clone(this->fText, that.fText, FALSE, TRUE, &uec);
+	this->fText = utext_clone(this->fText, that.fText, false, true, &uec);
 
 	//don't bother copying the character iterator, getText() is deprecated
 	clearCurrentCharIter();
@@ -72,20 +72,24 @@ CodePointBreakIterator::~CodePointBreakI
 	clearCurrentCharIter();
 }
 
+#if U_ICU_VERSION_MAJOR_NUM >= 70
+bool CodePointBreakIterator::operator==(const BreakIterator& that) const
+#else
 UBool CodePointBreakIterator::operator==(const BreakIterator& that) const
+#endif
 {
 	if (typeid(*this) != typeid(that)) {
-		return FALSE;
+		return false;
 	}
 
 	const CodePointBreakIterator& that2 =
 		static_cast<const CodePointBreakIterator&>(that);
 
 	if (!utext_equals(this->fText, that2.fText)) {
-		return FALSE;
+		return false;
 	}
 
-	return TRUE;
+	return true;
 }
 
 CodePointBreakIterator* CodePointBreakIterator::clone(void) const
@@ -106,7 +110,7 @@ CharacterIterator& CodePointBreakIterato
 
 UText *CodePointBreakIterator::getUText(UText *fillIn, UErrorCode &status) const
 {
-	return utext_clone(fillIn, this->fText, FALSE, TRUE, &status);
+	return utext_clone(fillIn, this->fText, false, true, &status);
 }
 
 void CodePointBreakIterator::setText(const UnicodeString &text)
@@ -125,7 +129,7 @@ void CodePointBreakIterator::setText(UTe
 		return;
 	}
 
-	this->fText = utext_clone(this->fText, text, FALSE, TRUE, &status);
+	this->fText = utext_clone(this->fText, text, false, true, &status);
 
 	clearCurrentCharIter();
 }
@@ -277,7 +281,7 @@ CodePointBreakIterator &CodePointBreakIt
 	}
 
 	int64_t pos = utext_getNativeIndex(this->fText);
-	this->fText = utext_clone(this->fText, input, FALSE, TRUE, &status);
+	this->fText = utext_clone(this->fText, input, false, true, &status);
 	if (U_FAILURE(status)) {
 		return *this;
 	}
