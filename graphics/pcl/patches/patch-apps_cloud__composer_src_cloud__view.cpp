$NetBSD: patch-apps_cloud__composer_src_cloud__view.cpp,v 1.1 2021/05/07 11:36:29 thor Exp $

Support VTK 9, from PR 4262

--- apps/cloud_composer/src/cloud_view.cpp.orig	2020-08-14 12:23:03.000000000 +0000
+++ apps/cloud_composer/src/cloud_view.cpp
@@ -5,20 +5,29 @@
 #include <pcl/apps/cloud_composer/point_selectors/selection_event.h>
 #include <pcl/apps/cloud_composer/point_selectors/manipulation_event.h>
 
+#include <vtkGenericOpenGLRenderWindow.h>
+
 #include <QDebug>
 
-#include <QVTKWidget.h>
 
 pcl::cloud_composer::CloudView::CloudView (QWidget* parent)
   : QWidget (parent)
 {
-  vis_.reset (new pcl::visualization::PCLVisualizer ("", false));
-  vis_->getInteractorStyle ()->setKeyboardModifier (pcl::visualization::INTERACTOR_KB_MOD_SHIFT);
+  qvtk_ = new PCLQVTKWidget(this);
   //Create the QVTKWidget
-  qvtk_ = new QVTKWidget (this);
-  qvtk_->SetRenderWindow (vis_->getRenderWindow ());
+#if VTK_MAJOR_VERSION > 8
+  auto renderer = vtkSmartPointer<vtkRenderer>::New();
+  auto renderWindow = vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New();
+  renderWindow->AddRenderer(renderer);
+  vis_.reset(new pcl::visualization::PCLVisualizer(renderer, renderWindow, "", false));
+#else
+  vis_.reset(new pcl::visualization::PCLVisualizer("", false));
+#endif // VTK_MAJOR_VERSION > 8
+  setRenderWindowCompat(*qvtk_, *(vis_->getRenderWindow()));
+  vis_->setupInteractor(getInteractorCompat(*qvtk_), getRenderWindowCompat(*qvtk_), style_switch_);
+  vis_->getInteractorStyle()->setKeyboardModifier(pcl::visualization::INTERACTOR_KB_MOD_SHIFT);
+  
   initializeInteractorSwitch ();
-  vis_->setupInteractor (qvtk_->GetInteractor (), qvtk_->GetRenderWindow (), style_switch_);
   
   QGridLayout *mainLayout = new QGridLayout (this);
   mainLayout-> addWidget (qvtk_,0,0);
@@ -28,13 +37,22 @@ pcl::cloud_composer::CloudView::CloudVie
   : QWidget (parent)
 {
   model_ = model;
-  vis_.reset (new pcl::visualization::PCLVisualizer ("", false));
- // vis_->getInteractorStyle ()->setKeyboardModifier (pcl::visualization::INTERACTOR_KB_MOD_SHIFT);
+  
+  qvtk_ = new PCLQVTKWidget(this);
   //Create the QVTKWidget
-  qvtk_ = new QVTKWidget (this);
-  qvtk_->SetRenderWindow (vis_->getRenderWindow ());
+#if VTK_MAJOR_VERSION > 8
+  auto renderer = vtkSmartPointer<vtkRenderer>::New();
+  auto renderWindow = vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New();
+  renderWindow->AddRenderer(renderer);
+  vis_.reset(new pcl::visualization::PCLVisualizer(renderer, renderWindow, "", false));
+#else
+  vis_.reset(new pcl::visualization::PCLVisualizer("", false));
+#endif // VTK_MAJOR_VERSION > 8
+  setRenderWindowCompat(*qvtk_, *(vis_->getRenderWindow()));
+  vis_->setupInteractor(getInteractorCompat(*qvtk_), getRenderWindowCompat(*qvtk_), style_switch_);
+  //vis_->getInteractorStyle()->setKeyboardModifier(pcl::visualization::INTERACTOR_KB_MOD_SHIFT);
+
   initializeInteractorSwitch ();
-  vis_->setupInteractor (qvtk_->GetInteractor (), qvtk_->GetRenderWindow (), style_switch_);
   setModel(model);
   
   QGridLayout *mainLayout = new QGridLayout (this);
@@ -57,9 +75,9 @@ pcl::cloud_composer::CloudView::setModel
   connectSignalsAndSlots();
   //Refresh the view
   qvtk_->show();
-  qvtk_->update ();
+  refresh();
   
- // vis_->addOrientationMarkerWidgetAxes (qvtk_->GetInteractor ());
+ // vis_->addOrientationMarkerWidgetAxes (getInteractorCompat(qvtk_));
 }
 
 void
@@ -76,7 +94,11 @@ pcl::cloud_composer::CloudView::connectS
 void
 pcl::cloud_composer::CloudView::refresh ()
 {
+#if VTK_MAJOR_VERSION > 8
+  qvtk_->renderWindow()->Render();
+#else
   qvtk_->update (); 
+#endif // VTK_MAJOR_VERSION > 8
 }
 
 void
@@ -88,7 +110,7 @@ pcl::cloud_composer::CloudView::itemChan
   {
     item->paintView (vis_);
   }
-  qvtk_->update ();
+  refresh();
 }
 
 
@@ -115,8 +137,7 @@ pcl::cloud_composer::CloudView::rowsInse
       rowsInserted(new_item->index(),0,new_item->rowCount ()-1);
   }
   
-  qvtk_->update ();
-
+  refresh();
 }
 
 void
@@ -143,20 +164,20 @@ pcl::cloud_composer::CloudView::rowsAbou
     if (item_to_remove->rowCount () > 0) 
       rowsAboutToBeRemoved(item_to_remove->index(),0,item_to_remove->rowCount ()-1);
   }
-  qvtk_->update ();
+  refresh();
 }
 
 
 void 
 pcl::cloud_composer::CloudView::paintEvent (QPaintEvent*)
 {
-  qvtk_->update ();
+  refresh();
 }
 
 void 
 pcl::cloud_composer::CloudView::resizeEvent (QResizeEvent*)
 {
-  qvtk_->update ();
+  refresh();
 }
 
 void
@@ -186,7 +207,7 @@ pcl::cloud_composer::CloudView::selected
       }
     }
   }
-  qvtk_->update ();
+  refresh();
 }
 
 void
@@ -204,14 +225,14 @@ pcl::cloud_composer::CloudView::setAxisV
   if (visible)
   {
     qDebug () << "Adding coordinate system!";
-    vis_->addOrientationMarkerWidgetAxes ( qvtk_->GetInteractor() );
+    vis_->addOrientationMarkerWidgetAxes(getInteractorCompat(*qvtk_));
   }
   else
   {
     vis_->removeOrientationMarkerWidgetAxes ();
   }
 
-  qvtk_->update ();
+  refresh();
 }
 
 void
@@ -224,7 +245,7 @@ pcl::cloud_composer::CloudView::addOrien
     axes_widget_ = vtkSmartPointer<vtkOrientationMarkerWidget>::New ();
     axes_widget_->SetOutlineColor ( 0.9300, 0.5700, 0.1300 );
     axes_widget_->SetOrientationMarker( axes );
-    axes_widget_->SetInteractor( qvtk_->GetInteractor () );
+    axes_widget_->SetInteractor(getInteractorCompat(*qvtk_));
     axes_widget_->SetViewport( 0.0, 0.0, 0.4, 0.4 );
     axes_widget_->SetEnabled( 1 );
     axes_widget_->InteractiveOn();
@@ -244,8 +265,6 @@ pcl::cloud_composer::CloudView::removeOr
   {
     axes_widget_->SetEnabled (false);
   }
-  
-  
 }
 
 ////////  Interactor Functions
@@ -255,7 +274,7 @@ pcl::cloud_composer::CloudView::initiali
 {
   style_switch_ = vtkSmartPointer<InteractorStyleSwitch>::New();
   style_switch_->initializeInteractorStyles (vis_, model_);
-  style_switch_->SetInteractor (qvtk_->GetInteractor ());
+  style_switch_->SetInteractor(getInteractorCompat(*qvtk_));
   style_switch_->setCurrentInteractorStyle (interactor_styles::PCL_VISUALIZER);
   
   //Connect the events!
