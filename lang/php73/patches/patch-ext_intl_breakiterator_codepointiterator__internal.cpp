$NetBSD: patch-ext_intl_breakiterator_codepointiterator__internal.cpp,v 1.1 2020/11/11 20:05:10 markd Exp $

Use stdbool true/false macros.

--- ext/intl/breakiterator/codepointiterator_internal.cpp.orig	2020-10-27 15:01:59.000000000 +0000
+++ ext/intl/breakiterator/codepointiterator_internal.cpp
@@ -58,7 +58,7 @@ CodePointBreakIterator& CodePointBreakIt
 		return *this;
 	}
 
-	this->fText = utext_clone(this->fText, that.fText, FALSE, TRUE, &uec);
+	this->fText = utext_clone(this->fText, that.fText, false, true, &uec);
 
 	//don't bother copying the character iterator, getText() is deprecated
 	clearCurrentCharIter();
@@ -78,17 +78,17 @@ CodePointBreakIterator::~CodePointBreakI
 UBool CodePointBreakIterator::operator==(const BreakIterator& that) const
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
@@ -109,7 +109,7 @@ CharacterIterator& CodePointBreakIterato
 
 UText *CodePointBreakIterator::getUText(UText *fillIn, UErrorCode &status) const
 {
-	return utext_clone(fillIn, this->fText, FALSE, TRUE, &status);
+	return utext_clone(fillIn, this->fText, false, true, &status);
 }
 
 void CodePointBreakIterator::setText(const UnicodeString &text)
@@ -128,7 +128,7 @@ void CodePointBreakIterator::setText(UTe
 		return;
 	}
 
-	this->fText = utext_clone(this->fText, text, FALSE, TRUE, &status);
+	this->fText = utext_clone(this->fText, text, false, true, &status);
 
 	clearCurrentCharIter();
 }
@@ -280,7 +280,7 @@ CodePointBreakIterator &CodePointBreakIt
 	}
 
 	int64_t pos = utext_getNativeIndex(this->fText);
-	this->fText = utext_clone(this->fText, input, FALSE, TRUE, &status);
+	this->fText = utext_clone(this->fText, input, false, true, &status);
 	if (U_FAILURE(status)) {
 		return *this;
 	}
