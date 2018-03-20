$NetBSD: patch-core_scripts_mk__util.py,v 1.1 2018/03/20 15:47:36 khorben Exp $

Add support for NetBSD.

--- core/scripts/mk_util.py.orig	2017-06-08 07:51:35.000000000 +0000
+++ core/scripts/mk_util.py
@@ -69,6 +69,7 @@ IS_WINDOWS=False
 IS_LINUX=False
 IS_OSX=False
 IS_FREEBSD=False
+IS_NETBSD=False
 IS_OPENBSD=False
 IS_CYGWIN=False
 IS_CYGWIN_MINGW=False
@@ -138,6 +139,9 @@ def is_linux():
 def is_freebsd():
     return IS_FREEBSD
 
+def is_netbsd():
+    return IS_NETBSD
+
 def is_openbsd():
     return IS_OPENBSD
 
@@ -598,6 +602,8 @@ elif os.name == 'posix':
         IS_LINUX=True
     elif os.uname()[0] == 'FreeBSD':
         IS_FREEBSD=True
+    elif os.uname()[0] == 'NetBSD':
+        IS_NETBSD=True
     elif os.uname()[0] == 'OpenBSD':
         IS_OPENBSD=True
     elif os.uname()[0][:6] == 'CYGWIN':
@@ -1223,7 +1229,7 @@ def get_so_ext():
     sysname = os.uname()[0]
     if sysname == 'Darwin':
         return 'dylib'
-    elif sysname == 'Linux' or sysname == 'FreeBSD' or sysname == 'OpenBSD':
+    elif sysname == 'Linux' or sysname == 'FreeBSD' or sysname == 'NetBSD' or sysname == 'OpenBSD':
         return 'so'
     elif sysname == 'CYGWIN':
         return 'dll'
@@ -1773,6 +1779,8 @@ class JavaDLLComponent(Component):
                 t = t.replace('PLATFORM', 'linux')
             elif IS_FREEBSD:
                 t = t.replace('PLATFORM', 'freebsd')
+            elif IS_NETBSD:
+                t = t.replace('PLATFORM', 'netbsd')
             elif IS_OPENBSD:
                 t = t.replace('PLATFORM', 'openbsd')
             elif IS_CYGWIN:
@@ -2445,6 +2453,13 @@ def mk_config():
             LDFLAGS        = '%s -lrt' % LDFLAGS
             SLIBFLAGS      = '-shared'
             SLIBEXTRAFLAGS = '%s -lrt' % SLIBEXTRAFLAGS
+        elif sysname == 'NetBSD':
+            CXXFLAGS       = '%s -fno-strict-aliasing -D_NETBSD_' % CXXFLAGS
+            OS_DEFINES     = '-D_NETBSD_'
+            SO_EXT         = '.so'
+            LDFLAGS        = '%s -lrt' % LDFLAGS
+            SLIBFLAGS      = '-shared'
+            SLIBEXTRAFLAGS = '%s -lrt' % SLIBEXTRAFLAGS
         elif sysname == 'OpenBSD':
             CXXFLAGS       = '%s -fno-strict-aliasing -D_OPENBSD_' % CXXFLAGS
             OS_DEFINES     = '-D_OPENBSD_'
