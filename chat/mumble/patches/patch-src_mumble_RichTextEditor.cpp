$NetBSD: patch-src_mumble_RichTextEditor.cpp,v 1.1 2019/06/17 08:08:31 nia Exp $

--- src/mumble/RichTextEditor.cpp.orig	2017-01-27 06:48:33.000000000 +0000
+++ src/mumble/RichTextEditor.cpp
@@ -32,10 +32,12 @@
 
 #include "RichTextEditor.h"
 
-#include "Global.h"
 #include "Log.h"
 #include "MainWindow.h"
 
+// We define a global macro called 'g'. This can lead to issues when included code uses 'g' as a type or parameter name (like protobuf 3.7 does). As such, for now, we have to make this our last include.
+#include "Global.h"
+
 RichTextHtmlEdit::RichTextHtmlEdit(QWidget *p) : QTextEdit(p) {
 	m_document = new LogDocument(this);
 	setDocument(m_document);
