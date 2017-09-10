$NetBSD: patch-qt_src_3rdparty_webkit_Source_WebCore_dom_DocumentMarkerController.cpp,v 1.1 2017/09/10 19:58:36 joerg Exp $

--- qt/src/3rdparty/webkit/Source/WebCore/dom/DocumentMarkerController.cpp.orig	2017-09-09 19:31:56.627182081 +0000
+++ qt/src/3rdparty/webkit/Source/WebCore/dom/DocumentMarkerController.cpp
@@ -59,7 +59,7 @@ void DocumentMarkerController::addMarker
     for (TextIterator markedText(range); !markedText.atEnd(); markedText.advance()) {
         RefPtr<Range> textPiece = markedText.range();
         int exception = 0;
-        DocumentMarker marker = {type, textPiece->startOffset(exception), textPiece->endOffset(exception), description, false};
+        DocumentMarker marker = {type, (unsigned)textPiece->startOffset(exception), (unsigned)textPiece->endOffset(exception), description, false};
         addMarker(textPiece->startContainer(exception), marker);
     }
 }
