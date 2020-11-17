$NetBSD: patch-Mac_BuildScript_build-installer.py,v 1.1 2020/11/17 19:33:15 sjmulder Exp $

Support for macOS 11 and Apple Silicon (ARM). Mostly backported from:
https://github.com/python/cpython/pull/22855

--- Mac/BuildScript/build-installer.py.orig	2020-09-23 12:36:32.000000000 +0000
+++ Mac/BuildScript/build-installer.py
@@ -116,7 +116,8 @@ WORKDIR = "/tmp/_py"
 DEPSRC = os.path.join(WORKDIR, 'third-party')
 DEPSRC = os.path.expanduser('~/Universal/other-sources')
 
-universal_opts_map = { '32-bit': ('i386', 'ppc',),
+universal_opts_map = { 'universal2': ('arm64', 'x86_64'),
+                       '32-bit': ('i386', 'ppc',),
                        '64-bit': ('x86_64', 'ppc64',),
                        'intel':  ('i386', 'x86_64'),
                        'intel-32':  ('i386',),
@@ -124,6 +125,7 @@ universal_opts_map = { '32-bit': ('i386'
                        '3-way':  ('ppc', 'i386', 'x86_64'),
                        'all':    ('i386', 'ppc', 'x86_64', 'ppc64',) }
 default_target_map = {
+        'universal2': '10.9',
         '64-bit': '10.5',
         '3-way': '10.5',
         'intel': '10.5',
@@ -190,6 +192,26 @@ EXPECTED_SHARED_LIBS = {}
 def internalTk():
     return getDeptargetTuple() >= (10, 6)
 
+def tweak_tcl_build(basedir, archList):
+    with open("Makefile", "r") as fp:
+        contents = fp.readlines()
+
+    # For reasons I don't understand the tcl configure script
+    # decides that some stdlib symbols aren't present, before
+    # deciding that strtod is broken.
+    new_contents = []
+    for line in contents:
+        if line.startswith("COMPAT_OBJS"):
+            # note: the space before strtod.o is intentional,
+            # the detection of a broken strtod results in
+            # "fixstrod.o" on this line.
+            for nm in ("strstr.o", "strtoul.o", " strtod.o"):
+                line = line.replace(nm, "")
+        new_contents.append(line)
+
+    with open("Makefile", "w") as fp:
+        fp.writelines(new_contents)
+
 # List of names of third party software built with this installer.
 # The names will be inserted into the rtf version of the License.
 THIRD_PARTY_LIBS = []
@@ -231,6 +253,7 @@ def library_recipes():
                     '--libdir=/Library/Frameworks/Python.framework/Versions/%s/lib'%(getVersion(),),
               ],
               useLDFlags=False,
+              buildrecipe=tweak_tcl_build,
               install='make TCL_LIBRARY=%(TCL_LIBRARY)s && make install TCL_LIBRARY=%(TCL_LIBRARY)s DESTDIR=%(DESTDIR)s'%{
                   "DESTDIR": shellQuote(os.path.join(WORKDIR, 'libraries')),
                   "TCL_LIBRARY": shellQuote('/Library/Frameworks/Python.framework/Versions/%s/lib/tcl8.6'%(getVersion())),
@@ -801,6 +824,7 @@ def build_universal_openssl(basedir, arc
         arch_opts = {
             "i386": ["darwin-i386-cc"],
             "x86_64": ["darwin64-x86_64-cc", "enable-ec_nistp_64_gcc_128"],
+            "arm64": ["darwin64-arm64-cc"],
             "ppc": ["darwin-ppc-cc"],
             "ppc64": ["darwin64-ppc-cc"],
         }
