$NetBSD: patch-core_libs_template_templateselector.cpp,v 1.1 2013/03/02 18:10:03 joerg Exp $

--- core/libs/template/templateselector.cpp.orig	2013-02-28 10:12:49.000000000 +0000
+++ core/libs/template/templateselector.cpp
@@ -72,7 +72,7 @@ public:
     Template          metadataTemplate;
 };
 
-TemplateSelector::TemplateSelector(QWidget* parent = 0)
+TemplateSelector::TemplateSelector(QWidget* parent)
     : KHBox(parent), d(new TemplateSelectorPriv)
 {
     d->label         = new QLabel(i18n("Template: "), this);
