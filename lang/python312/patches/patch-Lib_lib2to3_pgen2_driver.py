$NetBSD: patch-Lib_lib2to3_pgen2_driver.py,v 1.1 2023/10/02 20:07:15 adam Exp $

On systems where both of the conditions

1. LD_LIBRARY_PATH does _not_ take precedence over DT_RPATH
   (e.g. Linux)
2. A previous libpython with the same major.minor is already installed
   (e.g. a previous version of this package)

hold, the built python will be linked with the installed libpython,
causing it to report an old teeny version in sys.version_info while
staging the install. Then "make package" fails with PLIST mismatches for
{,Pattern}Grammar.*.pickle.

pkgsrc knows which version we're building. Pass that down instead.

In patch-Lib_distutils_unixccompiler.py, we override Python maintainers'
expectations for Linux builds in favor of pkgsrc's expectations for
builds on all platforms. This patch is needed because of that patch.

--- Lib/lib2to3/pgen2/driver.py.orig	2020-06-27 08:35:53.000000000 +0000
+++ Lib/lib2to3/pgen2/driver.py
@@ -107,7 +107,8 @@ def _generate_pickle_name(gt):
     head, tail = os.path.splitext(gt)
     if tail == ".txt":
         tail = ""
-    return head + tail + ".".join(map(str, sys.version_info)) + ".pickle"
+    sys_version_info = "@PKGVERSION_NOREV@" + ".final.0"
+    return head + tail + sys_version_info + ".pickle"
 
 
 def load_grammar(gt="Grammar.txt", gp=None,
