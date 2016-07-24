$NetBSD: patch-setup_build.py,v 1.1 2016/07/24 07:08:54 wiz Exp $

Add rpath to linker command.
Look in libtool directory for file.

--- setup/build.py.orig	2016-07-22 02:21:05.000000000 +0000
+++ setup/build.py
@@ -251,8 +251,7 @@ class Build(Command):
         return ['-I'+x for x in dirs]
 
     def lib_dirs_to_ldflags(self, dirs):
-        pref = '/LIBPATH:' if iswindows else '-L'
-        return [pref+x for x in dirs]
+        return ['-L'+x+' -Wl,-R'+x for x in dirs]
 
     def libraries_to_ldflags(self, dirs):
         pref = '' if iswindows else '-l'
@@ -452,7 +451,7 @@ class Build(Command):
         if iswindows:
             qmc += ['-spec', qmakespec]
         fext = 'dll' if iswindows else 'dylib' if isosx else 'so'
-        name = '%s%s.%s' % ('release/' if iswindows else 'lib', sip['target'], fext)
+        name = '%s%s.%s' % ('release/' if iswindows else '.libs/lib', sip['target'], fext)
         try:
             os.chdir(src_dir)
             if self.newer(dest, sip['headers'] + sip['sources'] + ext.sources + ext.headers):
