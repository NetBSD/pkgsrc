$NetBSD: patch-apps_modeler_src_cloud__mesh__item.cpp,v 1.1 2021/05/07 11:36:29 thor Exp $

Support VTK 9, from PR 4262

--- apps/modeler/src/cloud_mesh_item.cpp.orig	2020-08-14 12:23:03.000000000 +0000
+++ apps/modeler/src/cloud_mesh_item.cpp
@@ -156,12 +156,13 @@ void
 pcl::modeler::CloudMeshItem::createChannels()
 {
   RenderWindowItem* render_window_item = dynamic_cast<RenderWindowItem*>(parent());
-  addChild(new PointsActorItem(
-      this, cloud_mesh_, render_window_item->getRenderWindow()->GetRenderWindow()));
-  addChild(new NormalsActorItem(
-      this, cloud_mesh_, render_window_item->getRenderWindow()->GetRenderWindow()));
-  addChild(new SurfaceActorItem(
-      this, cloud_mesh_, render_window_item->getRenderWindow()->GetRenderWindow()));
+  vtkRenderWindow* win =
+      getRenderWindowCompat(*(render_window_item->getRenderWindow()));
+
+  addChild(new PointsActorItem(this, cloud_mesh_, win));
+  addChild(new NormalsActorItem(this, cloud_mesh_, win));
+  addChild(new SurfaceActorItem(this, cloud_mesh_, win));
+
   for (int i = 0, i_end = childCount(); i < i_end; ++i) {
     ChannelActorItem* child_item = dynamic_cast<ChannelActorItem*>(child(i));
     child_item->init();
@@ -242,7 +243,7 @@ pcl::modeler::CloudMeshItem::updateRende
   for (int i = 0, i_end = childCount(); i < i_end; ++i) {
     ChannelActorItem* child_item = dynamic_cast<ChannelActorItem*>(child(i));
     child_item->switchRenderWindow(
-        render_window_item->getRenderWindow()->GetRenderWindow());
+        getRenderWindowCompat(*render_window_item->getRenderWindow()));
   }
 
   render_window_item->getRenderWindow()->updateAxes();
