$NetBSD: patch-kopete_kopete_chatwindow_emoticonselector.cpp,v 1.1 2014/07/11 20:06:20 jperkin Exp $

Avoid "error: call of overloaded <func> is ambiguous"

--- kopete/kopete/chatwindow/emoticonselector.cpp.orig	2007-05-14 07:40:09.000000000 +0000
+++ kopete/kopete/chatwindow/emoticonselector.cpp
@@ -70,7 +70,7 @@ void EmoticonSelector::prepareList(void)
 	int row = 0;
 	int col = 0;
 	QMap<QString, QStringList> list = Kopete::Emoticons::self()->emoticonAndPicList();
-	int emoticonsPerRow = static_cast<int>(sqrt(list.count()));
+	int emoticonsPerRow = static_cast<int>(sqrt((float)list.count()));
 	//kdDebug(14000) << "emoticonsPerRow=" << emoticonsPerRow << endl;
 
 	if ( lay )
