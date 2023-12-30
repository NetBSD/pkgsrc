$NetBSD: patch-tools_qemu-xen_meson_mesonbuild_dependencies_ui.py,v 1.1 2023/12/30 18:52:38 gdt Exp $

Force off looking for sdl2-config because we do not buildlink it.
Resolves failure to build when SDL2 is installed.

Not submitted upstream because while lack of --disable-sdl2 is a bug,
they are unlikely to see it that way.

--- tools/qemu-xen/meson/mesonbuild/dependencies/ui.py.orig	2022-06-02 11:40:57.000000000 +0000
+++ tools/qemu-xen/meson/mesonbuild/dependencies/ui.py
@@ -132,8 +132,8 @@ class GnuStepDependency(ConfigToolDepend
 
 class SDL2DependencyConfigTool(ConfigToolDependency):
 
-    tools = ['sdl2-config']
-    tool_name = 'sdl2-config'
+    tools = ['sdl2-config-FAIL']
+    tool_name = 'sdl2-config-FAIL'
 
     def __init__(self, name: str, environment: 'Environment', kwargs: T.Dict[str, T.Any]):
         super().__init__(name, environment, kwargs)
