$NetBSD: patch-printimages_wizard_wizard.cpp,v 1.1 2013/03/02 18:08:48 joerg Exp $

--- printimages/wizard/wizard.cpp.orig	2013-02-28 12:09:11.000000000 +0000
+++ printimages/wizard/wizard.cpp
@@ -88,7 +88,7 @@ public:
     WizardPage ( KAssistantDialog* dialog, const QString& title )
         : QWidget ( dialog )
     {
-        setupUi ( this );
+        this->setupUi ( this );
         layout()->setMargin ( 0 );
         mPage = dialog->addPage ( this, title );
     }
