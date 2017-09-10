$NetBSD: patch-qt_src_3rdparty_webkit_Source_WebCore_dom_Element.cpp,v 1.1 2017/09/10 19:58:36 joerg Exp $

--- qt/src/3rdparty/webkit/Source/WebCore/dom/Element.cpp.orig	2016-08-23 06:13:30.000000000 +0000
+++ qt/src/3rdparty/webkit/Source/WebCore/dom/Element.cpp
@@ -1080,7 +1080,7 @@ void Element::recalcStyle(StyleChange ch
 {
     // Ref currentStyle in case it would otherwise be deleted when setRenderStyle() is called.
     RefPtr<RenderStyle> currentStyle(renderStyle());
-    bool hasParentStyle = parentNodeForRenderingAndStyle() ? parentNodeForRenderingAndStyle()->renderStyle() : false;
+    bool hasParentStyle = parentNodeForRenderingAndStyle() ? parentNodeForRenderingAndStyle()->renderStyle() != NULL : false;
     bool hasDirectAdjacentRules = currentStyle && currentStyle->childrenAffectedByDirectAdjacentRules();
     bool hasIndirectAdjacentRules = currentStyle && currentStyle->childrenAffectedByForwardPositionalRules();
 
