$NetBSD: patch-apps_modeler_src_render__window.cpp,v 1.1 2021/05/07 11:36:29 thor Exp $

Support VTK 9, from PR 4262

--- apps/modeler/src/render_window.cpp.orig	2020-08-14 12:23:03.000000000 +0000
+++ apps/modeler/src/render_window.cpp
@@ -52,7 +52,7 @@
 pcl::modeler::RenderWindow::RenderWindow(RenderWindowItem* render_window_item,
                                          QWidget* parent,
                                          Qt::WindowFlags flags)
-: QVTKWidget(parent, flags)
+: PCLQVTKWidget(parent, flags)
 , axes_(vtkSmartPointer<vtkCubeAxesActor>::New())
 , render_window_item_(render_window_item)
 {
@@ -76,7 +76,7 @@ pcl::modeler::RenderWindow::~RenderWindo
 void
 pcl::modeler::RenderWindow::initRenderer()
 {
-  vtkSmartPointer<vtkRenderWindow> win = GetRenderWindow();
+  vtkSmartPointer<vtkRenderWindow> win = getRenderWindowCompat(*this);
   vtkSmartPointer<vtkRenderer> renderer = vtkSmartPointer<vtkRenderer>::New();
   win->AddRenderer(renderer);
 
@@ -105,7 +105,7 @@ pcl::modeler::RenderWindow::focusInEvent
   dynamic_cast<SceneTree*>(render_window_item_->treeWidget())
       ->selectRenderWindowItem(render_window_item_);
 
-  QVTKWidget::focusInEvent(event);
+  PCLQVTKWidget::focusInEvent(event);
 }
 
 //////////////////////////////////////////////////////////////////////////////////////////////
@@ -130,7 +130,7 @@ pcl::modeler::RenderWindow::setTitle(con
 void
 pcl::modeler::RenderWindow::render()
 {
-  GetRenderWindow()->Render();
+  getRenderWindowCompat(*this)->Render();
 }
 
 //////////////////////////////////////////////////////////////////////////////////////////////
@@ -138,9 +138,11 @@ void
 pcl::modeler::RenderWindow::resetCamera()
 {
   double bounds[6];
-  GetRenderWindow()->GetRenderers()->GetFirstRenderer()->ComputeVisiblePropBounds(
-      bounds);
-  GetRenderWindow()->GetRenderers()->GetFirstRenderer()->ResetCamera(bounds);
+  getRenderWindowCompat(*this)
+      ->GetRenderers()
+      ->GetFirstRenderer()
+      ->ComputeVisiblePropBounds(bounds);
+  getRenderWindowCompat(*this)->GetRenderers()->GetFirstRenderer()->ResetCamera(bounds);
   render();
 }
 
@@ -148,14 +150,16 @@ pcl::modeler::RenderWindow::resetCamera(
 void
 pcl::modeler::RenderWindow::getBackground(double& r, double& g, double& b)
 {
-  GetRenderWindow()->GetRenderers()->GetFirstRenderer()->GetBackground(r, g, b);
+  getRenderWindowCompat(*this)->GetRenderers()->GetFirstRenderer()->GetBackground(
+      r, g, b);
 }
 
 //////////////////////////////////////////////////////////////////////////////////////////////
 void
 pcl::modeler::RenderWindow::setBackground(double r, double g, double b)
 {
-  GetRenderWindow()->GetRenderers()->GetFirstRenderer()->SetBackground(r, g, b);
+  getRenderWindowCompat(*this)->GetRenderers()->GetFirstRenderer()->SetBackground(
+      r, g, b);
 }
 
 //////////////////////////////////////////////////////////////////////////////////////////////
@@ -165,7 +169,7 @@ pcl::modeler::RenderWindow::updateAxes()
   vtkBoundingBox bb;
 
   vtkActorCollection* actors =
-      GetRenderWindow()->GetRenderers()->GetFirstRenderer()->GetActors();
+      getRenderWindowCompat(*this)->GetRenderers()->GetFirstRenderer()->GetActors();
 
   actors->InitTraversal();
   for (int i = 0, i_end = actors->GetNumberOfItems(); i < i_end; ++i) {
@@ -181,8 +185,10 @@ pcl::modeler::RenderWindow::updateAxes()
   double bounds[6];
   bb.GetBounds(bounds);
   axes_->SetBounds(bounds);
-  axes_->SetCamera(
-      GetRenderWindow()->GetRenderers()->GetFirstRenderer()->GetActiveCamera());
+  axes_->SetCamera(getRenderWindowCompat(*this)
+                       ->GetRenderers()
+                       ->GetFirstRenderer()
+                       ->GetActiveCamera());
 }
 
 //////////////////////////////////////////////////////////////////////////////////////////////
@@ -190,7 +196,8 @@ void
 pcl::modeler::RenderWindow::setShowAxes(bool flag)
 {
   if (flag)
-    GetRenderWindow()->GetRenderers()->GetFirstRenderer()->AddActor(axes_);
+    getRenderWindowCompat(*this)->GetRenderers()->GetFirstRenderer()->AddActor(axes_);
   else
-    GetRenderWindow()->GetRenderers()->GetFirstRenderer()->RemoveActor(axes_);
+    getRenderWindowCompat(*this)->GetRenderers()->GetFirstRenderer()->RemoveActor(
+        axes_);
 }
