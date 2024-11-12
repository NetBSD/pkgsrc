$NetBSD: patch-scribus_plugins_gettext_htmlim_htmlreader.cpp,v 1.1 2024/11/12 21:46:56 markd Exp $

.../scribus/plugins/gettext/htmlim/htmlreader.cpp:251:18: error: ambiguous overload for
 'operator==' (operand types are 'const QChar' and 'const char [2]')
  251 |    if (tmp.at(0) == "\n")

--- scribus/plugins/gettext/htmlim/htmlreader.cpp.orig	2024-06-15 14:22:25.000000000 +0000
+++ scribus/plugins/gettext/htmlim/htmlreader.cpp
@@ -248,7 +248,7 @@ bool HTMLReader::characters(const QStrin
 		bool lcis = (chr.length() > 0 && chr[0].isSpace());
 		if (inPre)
 		{
-			if (tmp.at(0) == "\n")
+			if (tmp.at(0) == QString("\n"))
 				tmp = tmp.right(tmp.length() - 2);
 		}
 		else
