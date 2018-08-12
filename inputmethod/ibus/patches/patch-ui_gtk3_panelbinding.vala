$NetBSD: patch-ui_gtk3_panelbinding.vala,v 1.1 2018/08/12 10:45:03 tsutsui Exp $

- pull upstream wayland fix:
 https://github.com/ibus/ibus/commit/aa0f4252ff965729b871c91b4ed089bf98963c0b

--- ui/gtk3/panelbinding.vala.orig	2018-08-08 08:29:14.000000000 +0000
+++ ui/gtk3/panelbinding.vala
@@ -237,9 +237,14 @@ class PanelBinding : IBus.PanelService {
         GLib.Object(connection : bus.get_connection(),
                     object_path : IBus.PATH_PANEL_EXTENSION_EMOJI);
 
+#if USE_GDK_WAYLAND
         Type instance_type = Gdk.Display.get_default().get_type();
         Type wayland_type = typeof(GdkWayland.Display);
         m_is_wayland = instance_type.is_a(wayland_type);
+#else
+        m_is_wayland = false;
+        warning("Checking Wayland is disabled");
+#endif
 
         m_bus = bus;
         m_application = application;
