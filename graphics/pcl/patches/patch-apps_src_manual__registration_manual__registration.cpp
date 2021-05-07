$NetBSD: patch-apps_src_manual__registration_manual__registration.cpp,v 1.1 2021/05/07 11:36:29 thor Exp $

Support VTK 9, from PR 4262

--- apps/src/manual_registration/manual_registration.cpp.orig	2020-08-14 12:23:03.000000000 +0000
+++ apps/src/manual_registration/manual_registration.cpp
@@ -48,6 +48,7 @@
 #include <vtkCamera.h>
 #include <vtkRenderWindow.h>
 #include <vtkRendererCollection.h>
+#include <vtkGenericOpenGLRenderWindow.h>
 
 using namespace pcl;
 
@@ -66,29 +67,46 @@ ManualRegistration::ManualRegistration()
   this->setWindowTitle("PCL Manual Registration");
 
   // Set up the source window
+#if VTK_MAJOR_VERSION > 8
+  auto renderer_src = vtkSmartPointer<vtkRenderer>::New();
+  auto renderWindow_src = vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New();
+  renderWindow_src->AddRenderer(renderer_src);
+  vis_src_.reset(new pcl::visualization::PCLVisualizer(renderer_src, renderWindow_src, "", false));
+#else
   vis_src_.reset(new pcl::visualization::PCLVisualizer("", false));
-  ui_->qvtk_widget_src->SetRenderWindow(vis_src_->getRenderWindow());
-  vis_src_->setupInteractor(ui_->qvtk_widget_src->GetInteractor(),
-                            ui_->qvtk_widget_src->GetRenderWindow());
+#endif // VTK_MAJOR_VERSION > 8
+  setRenderWindowCompat(*(ui_->qvtk_widget_src),*(vis_src_->getRenderWindow()));
+  vis_src_->setupInteractor(getInteractorCompat(*(ui_->qvtk_widget_src)),
+                            getRenderWindowCompat(*(ui_->qvtk_widget_src)));
+
   vis_src_->getInteractorStyle()->setKeyboardModifier(
       pcl::visualization::INTERACTOR_KB_MOD_SHIFT);
-  ui_->qvtk_widget_src->update();
 
   vis_src_->registerPointPickingCallback(&ManualRegistration::SourcePointPickCallback,
                                          *this);
 
   // Set up the destination window
+#if VTK_MAJOR_VERSION > 8
+  auto renderer_dst = vtkSmartPointer<vtkRenderer>::New();
+  auto renderWindow_dst = vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New();
+  renderWindow_dst->AddRenderer(renderer_dst);
+  vis_dst_.reset(new pcl::visualization::PCLVisualizer(renderer_dst, renderWindow_dst, "", false));
+#else
   vis_dst_.reset(new pcl::visualization::PCLVisualizer("", false));
-  ui_->qvtk_widget_dst->SetRenderWindow(vis_dst_->getRenderWindow());
-  vis_dst_->setupInteractor(ui_->qvtk_widget_dst->GetInteractor(),
-                            ui_->qvtk_widget_dst->GetRenderWindow());
+#endif // VTK_MAJOR_VERSION > 8
+  setRenderWindowCompat(*(ui_->qvtk_widget_dst), *(vis_dst_->getRenderWindow()));
+  vis_dst_->setupInteractor(getInteractorCompat(*(ui_->qvtk_widget_dst)),
+                            getRenderWindowCompat(*(ui_->qvtk_widget_dst)));
+
+
   vis_dst_->getInteractorStyle()->setKeyboardModifier(
-      pcl::visualization::INTERACTOR_KB_MOD_SHIFT);
-  ui_->qvtk_widget_dst->update();
+    pcl::visualization::INTERACTOR_KB_MOD_SHIFT);
 
   vis_dst_->registerPointPickingCallback(&ManualRegistration::DstPointPickCallback,
                                          *this);
-
+  // Render view
+  refreshView();
+  
   // Connect all buttons
   connect(ui_->confirmSrcPointButton,
           SIGNAL(clicked()),
@@ -236,8 +254,8 @@ ManualRegistration::orthoChanged(int sta
         ->GetActiveCamera()
         ->SetParallelProjection(1);
   }
-  ui_->qvtk_widget_src->update();
-  ui_->qvtk_widget_dst->update();
+
+  refreshView();
 }
 
 // TODO
@@ -274,8 +292,17 @@ ManualRegistration::timeoutSlot()
     }
     cloud_dst_modified_ = false;
   }
-  ui_->qvtk_widget_src->update();
+  refreshView();
+}
+
+void
+ManualRegistration::refreshView()
+{
+#if VTK_MAJOR_VERSION > 8
+  ui_->qvtk_widget_dst->renderWindow()->Render();
+#else
   ui_->qvtk_widget_dst->update();
+#endif // VTK_MAJOR_VERSION > 8
 }
 
 void
