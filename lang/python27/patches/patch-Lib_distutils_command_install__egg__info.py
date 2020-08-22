$NetBSD: patch-Lib_distutils_command_install__egg__info.py,v 1.2 2020/08/22 13:01:42 schmonz Exp $

On systems where both of the conditions

1. LD_LIBRARY_PATH does _not_ take precedence over DT_RPATH
   (e.g. Linux)
2. A previous libpython with the same major.minor is already installed
   (e.g. a previous version of this package)

hold, the built python will be linked with the installed libpython,
causing it to report an old teeny version in
self.distribution.get_version() while staging the install. Then "make
package" fails with PLIST mismatches for Python-2.7.XX-py2.7.egg-info.

pkgsrc knows which version we're building. Pass that down instead.

In patch-Lib_distutils_unixccompiler.py, we override Python maintainers'
expectations for Linux builds in favor of pkgsrc's expectations for
builds on all platforms. This patch is needed because of that patch.

--- Lib/distutils/command/install_egg_info.py.orig	2020-04-19 21:13:39.000000000 +0000
+++ Lib/distutils/command/install_egg_info.py
@@ -21,9 +21,13 @@ class install_egg_info(Command):
 
     def finalize_options(self):
         self.set_undefined_options('install_lib',('install_dir','install_dir'))
+        distribution_name = self.distribution.get_name()
+        distribution_version = self.distribution.get_version()
+        if distribution_name == "Python":
+            distribution_version = "@PKGVERSION_NOREV@"
         basename = "%s-%s-py%s.egg-info" % (
-            to_filename(safe_name(self.distribution.get_name())),
-            to_filename(safe_version(self.distribution.get_version())),
+            to_filename(safe_name(distribution_name)),
+            to_filename(safe_version(distribution_version)),
             sys.version[:3]
         )
         self.target = os.path.join(self.install_dir, basename)
