$NetBSD: patch-app_render_gdk.c,v 1.1 2013/07/16 12:11:29 prlw1 Exp $

Fix crash on start-up with newish glib2.
Bug 694025 - GLib drop support for adding interfaces after class_init
commit 213bdfe956bf8fe57c86316f68a09408fef1647e

--- app/render_gdk.c.orig	2009-11-07 17:13:53.000000000 +0000
+++ app/render_gdk.c
@@ -50,7 +50,21 @@ static void copy_to_window (DiaRenderer 
                 gpointer window,
                 int x, int y, int width, int height);
 
-static void dia_gdk_renderer_iface_init (DiaInteractiveRendererInterface* iface)
+typedef struct _DiaGdkInteractiveRenderer DiaGdkInteractiveRenderer;
+struct _DiaGdkInteractiveRenderer
+{
+  DiaGdkRenderer parent_instance; /*!< inheritance in object oriented C */
+};
+typedef struct _DiaGdkInteractiveRendererClass DiaGdkInteractiveRendererClass;
+struct _DiaGdkInteractiveRendererClass
+{
+  DiaGdkRendererClass parent_class; /*!< the base class */
+};
+#define DIA_TYPE_GDK_INTERACTIVE_RENDERER           (dia_gdk_interactive_renderer_get_type ())
+#define DIA_GDK_INTERACTIVE_RENDERER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), DIA_TYPE_GDK_INTERACTIVE_RENDERER, DiaGdkInteractiveRenderer))
+
+static void
+dia_gdk_renderer_iface_init (DiaInteractiveRendererInterface* iface)
 {
   iface->clip_region_clear = clip_region_clear;
   iface->clip_region_add_rect = clip_region_add_rect;
@@ -61,35 +75,35 @@ static void dia_gdk_renderer_iface_init 
   iface->set_size = set_size;
 }
 
+G_DEFINE_TYPE_WITH_CODE (DiaGdkInteractiveRenderer, dia_gdk_interactive_renderer, DIA_TYPE_GDK_RENDERER,
+			 G_IMPLEMENT_INTERFACE (DIA_TYPE_INTERACTIVE_RENDERER_INTERFACE, dia_gdk_renderer_iface_init));
+
+static void
+dia_gdk_interactive_renderer_class_init(DiaGdkInteractiveRendererClass *klass)
+{
+}
+static void
+dia_gdk_interactive_renderer_init(DiaGdkInteractiveRenderer *object)
+{
+  DiaGdkInteractiveRenderer *ia_renderer = DIA_GDK_INTERACTIVE_RENDERER (object);
+  DiaGdkRenderer *renderer = DIA_GDK_RENDERER(object);
+  DiaRenderer *dia_renderer = DIA_RENDERER(object);
+  
+  dia_renderer->is_interactive = 1;
+
+  renderer->gc = NULL;
+  renderer->pixmap = NULL;
+  renderer->clip_region = NULL;
+}
+
 DiaRenderer *
 new_gdk_renderer(DDisplay *ddisp)
 {
   DiaGdkRenderer *renderer;
   GType renderer_type = 0;
 
-  renderer = g_object_new (DIA_TYPE_GDK_RENDERER, NULL);
+  renderer = g_object_new (DIA_TYPE_GDK_INTERACTIVE_RENDERER, NULL);
   renderer->transform = dia_transform_new (&ddisp->visible, &ddisp->zoom_factor);
-  if (!DIA_GET_INTERACTIVE_RENDERER_INTERFACE (renderer))
-    {
-      static const GInterfaceInfo irenderer_iface_info = 
-      {
-        (GInterfaceInitFunc) dia_gdk_renderer_iface_init,
-        NULL,           /* iface_finalize */
-        NULL            /* iface_data     */
-      };
-
-      renderer_type = DIA_TYPE_GDK_RENDERER;
-      /* register the interactive renderer interface */
-      g_type_add_interface_static (renderer_type,
-                                   DIA_TYPE_INTERACTIVE_RENDERER_INTERFACE,
-                                   &irenderer_iface_info);
-
-    }
-  renderer->parent_instance.is_interactive = 1;
-  renderer->gc = NULL;
-
-  renderer->pixmap = NULL;
-  renderer->clip_region = NULL;
 
   return DIA_RENDERER(renderer);
 }
