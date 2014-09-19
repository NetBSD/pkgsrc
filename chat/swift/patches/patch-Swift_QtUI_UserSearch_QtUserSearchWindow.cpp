$NetBSD: patch-Swift_QtUI_UserSearch_QtUserSearchWindow.cpp,v 1.1 2014/09/19 07:05:24 wiz Exp $

Fix build with boost-1.56.0. From upstream git.

--- Swift/QtUI/UserSearch/QtUserSearchWindow.cpp.orig	2012-12-22 12:23:58.000000000 +0000
+++ Swift/QtUI/UserSearch/QtUserSearchWindow.cpp
@@ -221,7 +221,7 @@ void QtUserSearchWindow::setSearchFields
 		fieldsPage_->setFormWidget(new QtFormWidget(fields->getForm(), fieldsPage_));
 	} else {
 		fieldsPage_->setFormWidget(NULL);
-		bool enabled[8] = {fields->getNick(), fields->getNick(), fields->getFirst(), fields->getFirst(), fields->getLast(), fields->getLast(), fields->getEMail(), fields->getEMail()};
+		bool enabled[8] = {!!fields->getNick(), !!fields->getNick(), !!fields->getFirst(), !!fields->getFirst(), !!fields->getLast(), !!fields->getLast(), !!fields->getEMail(), !!fields->getEMail()};
 		QWidget* legacySearchWidgets[8] = {fieldsPage_->nickInputLabel_, fieldsPage_->nickInput_, fieldsPage_->firstInputLabel_, fieldsPage_->firstInput_, fieldsPage_->lastInputLabel_, fieldsPage_->lastInput_, fieldsPage_->emailInputLabel_, fieldsPage_->emailInput_};
 		for (int i = 0; i < 8; i++) {
 			legacySearchWidgets[i]->setVisible(enabled[i]);
