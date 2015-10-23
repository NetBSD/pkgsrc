$NetBSD: patch-buildtools_wafadmin_Tools_ccroot.py,v 1.2 2015/10/23 19:52:41 tnn Exp $

--- buildtools/wafadmin/Tools/ccroot.py.orig	2014-09-16 18:04:31.000000000 +0000
+++ buildtools/wafadmin/Tools/ccroot.py
@@ -583,6 +583,9 @@ def apply_vnum(self):
 	if libname.endswith('.dylib'):
 		name3 = libname.replace('.dylib', '.%s.dylib' % self.vnum)
 		name2 = libname.replace('.dylib', '.%s.dylib' % nums[0])
+                iname = name2.replace(".inst", "")
+                self.env.append_value('LINKFLAGS', '-install_name')
+                self.env.append_value('LINKFLAGS', self.env.PREFIX + '/lib/' + iname)
 	else:
 		name3 = libname + '.' + self.vnum
 		name2 = libname + '.' + nums[0]
