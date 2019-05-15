$NetBSD: patch-buildtools_wafsamba_samba__install.py,v 1.1 2019/05/15 07:51:19 adam Exp $

Apply correct install_name on Darwin.

--- buildtools/wafsamba/samba_install.py.orig	2019-01-14 22:24:44.000000000 +0000
+++ buildtools/wafsamba/samba_install.py
@@ -151,6 +151,8 @@ def install_library(self):
             bld.symlink_as(os.path.join(install_path, install_link), os.path.basename(install_name))
         if dev_link:
             bld.symlink_as(os.path.join(install_path, dev_link), os.path.basename(install_name))
+        if getattr(self, 'samba_type', None) != 'PYTHON' and self.env.MACOSX_DEPLOYMENT_TARGET:
+            self.env.append_value('LINKFLAGS', ['-install_name', os.path.join(install_path, install_name)])
     finally:
         bld.all_envs['default'] = default_env
 
