$NetBSD: patch-buildtools_wafsamba_samba__install.py,v 1.1 2018/12/22 08:55:30 adam Exp $

Apply correct install_name on Darwin.

--- buildtools/wafsamba/samba_install.py.orig	2018-07-12 08:23:36.000000000 +0000
+++ buildtools/wafsamba/samba_install.py
@@ -150,6 +150,9 @@ def install_library(self):
             bld.symlink_as(os.path.join(install_path, install_link), os.path.basename(install_name))
         if dev_link:
             bld.symlink_as(os.path.join(install_path, dev_link), os.path.basename(install_name))
+        if getattr(self, 'samba_type', None) != 'PYTHON' and '-dynamiclib' in self.env['LINKFLAGS']:
+            self.env.append_value('LINKFLAGS', '-install_name')
+            self.env.append_value('LINKFLAGS', os.path.join(install_path, install_name))
     finally:
         bld.all_envs['default'] = default_env
 
