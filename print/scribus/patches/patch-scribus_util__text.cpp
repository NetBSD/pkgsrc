$NetBSD: patch-scribus_util__text.cpp,v 1.1 2025/11/10 13:54:53 wiz Exp $

Fix build with qt 6.9.
https://github.com/scribusproject/scribus/commit/f553dce73905d11b301901dc039e973c18adf0a5

--- scribus/util_text.cpp.orig	2025-01-25 21:57:41.000000000 +0000
+++ scribus/util_text.cpp
@@ -100,10 +100,12 @@ QString stringToUnicode(const QString &t
 	QString out;
 
 	for (auto c : text)
-		out += QString("U+%1,").arg(c.unicode(), 4, 16, QChar('0')).toUpper();
-
-	return out.mid(0, out.length() -1);
+	{
+		auto u = static_cast<uint>(c.unicode());
+		out += QString("U+%1,").arg(u, 4, 16, QChar('0')).toUpper();
+	}
 
+	return out.mid(0, out.length() - 1);
 }
 
 QString unicodeToString(const QString &text)
