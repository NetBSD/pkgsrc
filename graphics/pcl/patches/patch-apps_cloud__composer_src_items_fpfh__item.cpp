$NetBSD: patch-apps_cloud__composer_src_items_fpfh__item.cpp,v 1.1 2021/05/07 11:36:29 thor Exp $

Support VTK 9, from PR 4262

--- apps/cloud_composer/src/items/fpfh_item.cpp.orig	2020-08-14 12:23:03.000000000 +0000
+++ apps/cloud_composer/src/items/fpfh_item.cpp
@@ -3,8 +3,6 @@
 
 #include <QGridLayout>
 
-#include <QVTKWidget.h>
-
 pcl::cloud_composer::FPFHItem::FPFHItem (QString name, const pcl::PointCloud<pcl::FPFHSignature33>::Ptr& fpfh_ptr, double radius)
   : CloudComposerItem (std::move(name))
   , fpfh_ptr_ (fpfh_ptr)
@@ -40,7 +38,7 @@ pcl::cloud_composer::FPFHItem::getInspec
   if (!plot_)
   {
     plot_.reset (new pcl::visualization::PCLPlotter);
-    qvtk_ = new QVTKWidget ();
+    qvtk_ = new PCLQVTKWidget();
     hist_page_ = new QWidget ();
     QGridLayout *mainLayout = new QGridLayout (hist_page_);
     mainLayout-> addWidget (qvtk_,0,0);
@@ -49,10 +47,15 @@ pcl::cloud_composer::FPFHItem::getInspec
   //Plot the histogram
   plot_->addFeatureHistogram (*fpfh_ptr_, fpfh_ptr_->width, data(ItemDataRole::ITEM_ID).toString().toStdString ());
   //Set the render window of the QVTK widget, update
-  plot_->setViewInteractor (vtkSmartPointer<vtkRenderWindowInteractor> (qvtk_->GetInteractor ()));
-  qvtk_->SetRenderWindow (plot_->getRenderWindow ());
+  plot_->setViewInteractor(getInteractorCompat(*qvtk_));
+  setRenderWindowCompat(*qvtk_, *(plot_->getRenderWindow()));
+#if VTK_MAJOR_VERSION > 8
+  qvtk_->renderWindow()->Render();
+#else
+  qvtk_->update();
+#endif // VTK_MAJOR_VERSION > 8
   qvtk_->show ();
-  qvtk_->update ();
+  
   
   QMap <QString, QWidget*> tabs;
   tabs.insert ("Histogram",hist_page_);
