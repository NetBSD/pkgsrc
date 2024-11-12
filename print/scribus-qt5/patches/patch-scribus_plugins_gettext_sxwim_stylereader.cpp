$NetBSD: patch-scribus_plugins_gettext_sxwim_stylereader.cpp,v 1.1 2024/11/12 21:46:56 markd Exp $

.../scribus/plugins/gettext/sxwim/stylereader.cpp:659:44: error: ambiguous overload for
 'operator!=' (operand types are 'const QChar' and 'const char [2]')

--- scribus/plugins/gettext/sxwim/stylereader.cpp.orig	2024-06-15 14:22:26.000000000 +0000
+++ scribus/plugins/gettext/sxwim/stylereader.cpp
@@ -274,11 +274,11 @@ void StyleReader::styleProperties(const 
 			currentStyle->getFont()->setHscale(static_cast<int>(getSize(attrValue, -1.0)));
 		else if ((attrName == "style:text-position") &&
 				 ((attrValue.indexOf("sub") != -1) ||
-				  ((attrValue.at(0) == "-") && (attrValue.at(0) != "0"))))
+				  ((attrValue.at(0) == QString("-")) && (attrValue.at(0) != QString("0")))))
 			currentStyle->getFont()->toggleEffect(SUBSCRIPT);
 		else if ((attrName == "style:text-position") &&
 				 ((attrValue.indexOf("super") != -1) ||
-				  ((attrValue.at(0) != "-") && (attrValue.at(0) != "0"))))
+				  ((attrValue.at(0) != QString("-")) && (attrValue.at(0) != QString("0")))))
 			currentStyle->getFont()->toggleEffect(SUPERSCRIPT);
 		else if ((attrName == "fo:margin-top") && (pstyle != nullptr))
 			pstyle->setSpaceAbove(getSize(attrValue));
@@ -652,11 +652,11 @@ bool StyleReader::updateStyle(gtStyle* s
 		style->getFont()->setHscale(static_cast<int>(getSize(value, -1.0)));
 	else if ((key == "style:text-position") &&
 			 ((value.indexOf("sub") != -1) ||
-			  ((value.at(0) == "-") && (value.at(0) != "0"))))
+			  ((value.at(0) == QString("-")) && (value.at(0) != QString("0")))))
 		style->getFont()->toggleEffect(SUBSCRIPT);
 	else if ((key == "style:text-position") &&
 			 ((value.indexOf("super") != -1) ||
-			  ((value.at(0) != "-") && (value.at(0) != "0"))))
+			  ((value.at(0) != QString("-")) && (value.at(0) != QString("0")))))
 		style->getFont()->toggleEffect(SUPERSCRIPT);
 	else if ((key == "fo:margin-top") && (pstyle != nullptr))
 		pstyle->setSpaceAbove(getSize(value));
