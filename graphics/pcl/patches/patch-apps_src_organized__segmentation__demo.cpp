$NetBSD: patch-apps_src_organized__segmentation__demo.cpp,v 1.1 2021/05/07 11:36:29 thor Exp $

Support VTK 9, from PR 4262

--- apps/src/organized_segmentation_demo.cpp.orig	2020-08-14 12:23:03.000000000 +0000
+++ apps/src/organized_segmentation_demo.cpp
@@ -12,6 +12,8 @@
 #include <QObject>
 
 #include <vtkRenderWindow.h>
+#include <vtkRendererCollection.h>
+#include <vtkGenericOpenGLRenderWindow.h>
 
 // #include <boost/filesystem.hpp>  // for boost::filesystem::directory_iterator
 #include <boost/signals2/connection.hpp> // for boost::signals2::connection
@@ -204,13 +206,23 @@ OrganizedSegmentationDemo::OrganizedSegm
   ui_->setupUi(this);
 
   this->setWindowTitle("PCL Organized Connected Component Segmentation Demo");
+  
+#if VTK_MAJOR_VERSION > 8
+  auto renderer = vtkSmartPointer<vtkRenderer>::New();
+  auto renderWindow = vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New();
+  renderWindow->AddRenderer(renderer);
+  vis_.reset(new pcl::visualization::PCLVisualizer(renderer, renderWindow, "", false));
+#else
   vis_.reset(new pcl::visualization::PCLVisualizer("", false));
-  ui_->qvtk_widget->SetRenderWindow(vis_->getRenderWindow());
-  vis_->setupInteractor(ui_->qvtk_widget->GetInteractor(),
-                        ui_->qvtk_widget->GetRenderWindow());
+#endif // VTK_MAJOR_VERSION > 8
+  setRenderWindowCompat(*(ui_->qvtk_widget),*(vis_->getRenderWindow()));
+  vis_->setupInteractor(getInteractorCompat(*(ui_->qvtk_widget)), getRenderWindowCompat(*(ui_->qvtk_widget)));
+  
+  refreshView();
+  
   vis_->getInteractorStyle()->setKeyboardModifier(
       pcl::visualization::INTERACTOR_KB_MOD_SHIFT);
-  ui_->qvtk_widget->update();
+  
 
   std::function<void(const CloudConstPtr&)> f = [this](const CloudConstPtr& cloud) {
     cloud_cb(cloud);
@@ -309,6 +321,16 @@ OrganizedSegmentationDemo::OrganizedSegm
 }
 
 void
+OrganizedSegmentationDemo::refreshView()
+{
+#if VTK_MAJOR_VERSION > 8
+  ui_->qvtk_widget->renderWindow()->Render();
+#else
+  ui_->qvtk_widget->update();
+#endif // VTK_MAJOR_VERSION > 8
+}
+
+void
 OrganizedSegmentationDemo::cloud_cb(const CloudConstPtr& cloud)
 {
   if (!capture_)
@@ -440,8 +462,7 @@ OrganizedSegmentationDemo::timeoutSlot()
       data_modified_ = false;
     }
   }
-
-  ui_->qvtk_widget->update();
+  refreshView();
 }
 
 void
