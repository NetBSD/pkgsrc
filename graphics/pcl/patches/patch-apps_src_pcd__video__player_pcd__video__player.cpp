$NetBSD: patch-apps_src_pcd__video__player_pcd__video__player.cpp,v 1.1 2021/05/07 11:36:29 thor Exp $

Support VTK 9, from PR 4262

--- apps/src/pcd_video_player/pcd_video_player.cpp.orig	2020-08-14 12:23:03.000000000 +0000
+++ apps/src/pcd_video_player/pcd_video_player.cpp
@@ -35,6 +35,8 @@
  *
  */
 
+#include <ui_pcd_video_player.h>
+
 #include <pcl/apps/pcd_video_player.h>
 #include <pcl/io/pcd_io.h>
 #include <pcl/point_types.h>
@@ -51,6 +53,7 @@
 #include <vtkCamera.h>
 #include <vtkRenderWindow.h>
 #include <vtkRendererCollection.h>
+#include <vtkGenericOpenGLRenderWindow.h>
 
 #include <fstream>
 #include <iostream>
@@ -80,14 +83,21 @@ PCDVideoPlayer::PCDVideoPlayer()
   // Setup the cloud pointer
   cloud_.reset(new pcl::PointCloud<pcl::PointXYZRGBA>);
 
-  // Set up the qvtk window
+  //Create the QVTKWidget
+#if VTK_MAJOR_VERSION > 8
+  auto renderer = vtkSmartPointer<vtkRenderer>::New();
+  auto renderWindow = vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New();
+  renderWindow->AddRenderer(renderer);
+  vis_.reset(new pcl::visualization::PCLVisualizer(renderer, renderWindow, "", false));
+#else
   vis_.reset(new pcl::visualization::PCLVisualizer("", false));
-  ui_->qvtkWidget->SetRenderWindow(vis_->getRenderWindow());
-  vis_->setupInteractor(ui_->qvtkWidget->GetInteractor(),
-                        ui_->qvtkWidget->GetRenderWindow());
-  vis_->getInteractorStyle()->setKeyboardModifier(
-      pcl::visualization::INTERACTOR_KB_MOD_SHIFT);
-  ui_->qvtkWidget->update();
+#endif // VTK_MAJOR_VERSION > 8
+  setRenderWindowCompat(*(ui_->qvtk_widget),*(vis_->getRenderWindow()));
+  vis_->setupInteractor(getInteractorCompat(*(ui_->qvtk_widget)), getRenderWindowCompat(*(ui_->qvtk_widget)));
+
+  vis_->getInteractorStyle()->setKeyboardModifier(pcl::visualization::INTERACTOR_KB_MOD_SHIFT);
+
+  refreshView();
 
   // Connect all buttons
   connect(ui_->playButton, SIGNAL(clicked()), this, SLOT(playButtonPressed()));
@@ -258,7 +268,8 @@ PCDVideoPlayer::timeoutSlot()
     }
     cloud_modified_ = false;
   }
-  ui_->qvtkWidget->update();
+
+  refreshView();
 }
 
 void
@@ -270,6 +281,16 @@ PCDVideoPlayer::indexSliderValueChanged(
 }
 
 void
+PCDVideoPlayer::refreshView()
+{
+#if VTK_MAJOR_VERSION > 8
+  ui_->qvtk_widget->renderWindow()->Render();
+#else
+  ui_->qvtk_widget->update();
+#endif // VTK_MAJOR_VERSION > 8
+}
+
+void
 print_usage()
 {
   // clang-format off
