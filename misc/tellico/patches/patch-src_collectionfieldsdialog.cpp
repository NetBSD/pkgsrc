$NetBSD: patch-src_collectionfieldsdialog.cpp,v 1.1 2013/01/17 15:58:01 joerg Exp $

--- src/collectionfieldsdialog.cpp.orig	2012-01-15 21:30:40.000000000 +0000
+++ src/collectionfieldsdialog.cpp
@@ -55,9 +55,9 @@
 #include <QGridLayout>
 
 using namespace Tellico;
-using Tellico::FieldListItem;
 using Tellico::CollectionFieldsDialog;
 
+namespace Tellico {
 class FieldListItem : public Tellico::GUI::ListWidgetItem {
 public:
   FieldListItem(QListWidget* parent_, Data::FieldPtr field_) : GUI::ListWidgetItem(field_->title(), parent_), m_field(field_) {}
@@ -68,6 +68,7 @@ public:
 private:
   Data::FieldPtr m_field;
 };
+}
 
 CollectionFieldsDialog::CollectionFieldsDialog(Tellico::Data::CollPtr coll_, QWidget* parent_)
     : KDialog(parent_),
