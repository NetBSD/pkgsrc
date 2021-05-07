$NetBSD: patch-apps_src_openni__passthrough.cpp,v 1.1 2021/05/07 11:36:29 thor Exp $

Support VTK 9, from PR 4262

--- apps/src/openni_passthrough.cpp.orig	2020-08-14 12:23:03.000000000 +0000
+++ apps/src/openni_passthrough.cpp
@@ -35,6 +35,8 @@
  *
  */
 
+#include <ui_openni_passthrough.h>
+
 #include <pcl/apps/openni_passthrough.h>
 #include <pcl/console/parse.h>
 
@@ -44,6 +46,8 @@
 #include <QObject>
 
 #include <vtkRenderWindow.h>
+#include <vtkRendererCollection.h>
+#include <vtkGenericOpenGLRenderWindow.h>
 
 #include <thread>
 
@@ -61,13 +65,21 @@ OpenNIPassthrough::OpenNIPassthrough(pcl
   ui_->setupUi(this);
 
   this->setWindowTitle("PCL OpenNI PassThrough Viewer");
+    //Create the QVTKWidget
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
-  vis_->getInteractorStyle()->setKeyboardModifier(
-      pcl::visualization::INTERACTOR_KB_MOD_SHIFT);
-  ui_->qvtk_widget->update();
+#endif // VTK_MAJOR_VERSION > 8
+  setRenderWindowCompat(*(ui_->qvtk_widget),*(vis_->getRenderWindow()));
+  vis_->setupInteractor(getInteractorCompat(*(ui_->qvtk_widget)), getRenderWindowCompat(*(ui_->qvtk_widget)));
+  
+  vis_->getInteractorStyle()->setKeyboardModifier(pcl::visualization::INTERACTOR_KB_MOD_SHIFT);
+  
+  refreshView();
 
   // Start the OpenNI data acquision
   std::function<void(const CloudConstPtr&)> f = [this](const CloudConstPtr& cloud) {
@@ -125,6 +137,16 @@ OpenNIPassthrough::timeoutSlot()
   ui_->qvtk_widget->update();
 }
 
+void
+OpenNIPassthrough::refreshView()
+{
+#if VTK_MAJOR_VERSION > 8
+  ui_->qvtk_widget->renderWindow()->Render();
+#else
+  ui_->qvtk_widget->update();
+#endif // VTK_MAJOR_VERSION > 8
+}
+
 int
 main(int argc, char** argv)
 {
