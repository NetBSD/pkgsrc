$NetBSD: patch-src_insets_InsetText.cpp,v 1.1 2013/05/09 13:56:58 joerg Exp $

--- src/insets/InsetText.cpp.orig	2013-05-09 12:13:13.000000000 +0000
+++ src/insets/InsetText.cpp
@@ -62,7 +62,6 @@ using namespace std;
 using namespace lyx::support;
 
 using boost::bind;
-using boost::ref;
 
 namespace lyx {
 
@@ -353,7 +352,7 @@ int InsetText::docbook(odocstream & os, 
 void InsetText::validate(LaTeXFeatures & features) const
 {
 	for_each(paragraphs().begin(), paragraphs().end(),
-		 bind(&Paragraph::validate, _1, ref(features)));
+		 bind(&Paragraph::validate, _1, boost::ref(features)));
 }
 
 
@@ -435,7 +434,7 @@ void InsetText::appendParagraphs(Paragra
 		       distance(pl.begin(), ins) - 1);
 
 	for_each(pit, plist.end(),
-		 bind(&ParagraphList::push_back, ref(pl), _1));
+		 bind(&ParagraphList::push_back, boost::ref(pl), _1));
 }
 
 
