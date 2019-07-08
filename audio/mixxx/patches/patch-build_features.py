$NetBSD: patch-build_features.py,v 1.1 2019/07/08 16:46:32 nia Exp $

- Use pkg-config on BSD too where possible.
- Fix the name of the hidapi library.

--- build/features.py.orig	2019-04-22 07:50:04.000000000 +0000
+++ build/features.py
@@ -83,9 +83,9 @@ class HID(Feature):
         if not self.enabled(build):
             return
 
-        if build.platform_is_linux:
+        if build.platform_is_linux or build.platform_is_bsd:
             # Try using system lib
-            if not conf.CheckLib(['hidapi-libusb', 'libhidapi-libusb']):
+            if not conf.CheckLib(['hidapi']):
                 # No System Lib found
                 self.INTERNAL_LINK = True
                 build.env.ParseConfig(
@@ -95,7 +95,7 @@ class HID(Feature):
                     raise Exception(
                            'Did not find the libusb 1.0 development library or its header file')
             else:
-                build.env.ParseConfig('pkg-config hidapi-libusb --silence-errors --cflags --libs')
+                build.env.ParseConfig('pkg-config hidapi --silence-errors --cflags --libs')
 
 
             # Optionally add libpthread and librt. Some distros need this.
@@ -129,7 +129,7 @@ class HID(Feature):
                 # setupapi.
                 sources.append(
                     os.path.join(self.HIDAPI_INTERNAL_PATH, "windows/hid.c"))
-            elif build.platform_is_linux:
+            elif build.platform_is_linux or build.platform_is_bsd:
                 # hidapi compiles the libusb implementation by default on Linux
                 sources.append(
                     os.path.join(self.HIDAPI_INTERNAL_PATH, 'libusb/hid.c'))
@@ -147,14 +147,14 @@ class Bulk(Feature):
     def enabled(self, build):
         # For now only make Bulk default on Linux only. Turn on for all
         # platforms after the 1.11.0 release.
-        is_default = 1 if build.platform_is_linux else 0
+        is_default = 1 if build.platform_is_linux or build.platform_is_bsd else 0
         build.flags['bulk'] = util.get_flags(build.env, 'bulk', is_default)
         if int(build.flags['bulk']):
             return True
         return False
 
     def add_options(self, build, vars):
-        is_default = 1 if build.platform_is_linux else 0
+        is_default = 1 if build.platform_is_linux or build.platform_is_bsd else 0
         vars.Add('bulk',
                  'Set to 1 to enable USB Bulk controller support.', is_default)
 
@@ -409,7 +409,7 @@ class Vamp(Feature):
         # FFTW3 support
         have_fftw3_h = conf.CheckHeader('fftw3.h')
         have_fftw3 = conf.CheckLib('fftw3', autoadd=False)
-        if have_fftw3_h and have_fftw3 and build.platform_is_linux:
+        if have_fftw3_h and have_fftw3 and (build.platform_is_linux or build.platform_is_bsd):
             build.env.Append(CPPDEFINES='HAVE_FFTW3')
             build.env.ParseConfig(
                 'pkg-config fftw3 --silence-errors --cflags --libs')
@@ -1307,7 +1307,7 @@ class Battery(Feature):
             return ["util/battery/batterywindows.cpp"]
         elif build.platform_is_osx:
             return ["util/battery/batterymac.cpp"]
-        elif build.platform_is_linux:
+        elif build.platform_is_linux or build.platform_is_bsd:
             return ["util/battery/batterylinux.cpp"]
         else:
             raise Exception('Battery support is not implemented for the target platform.')
