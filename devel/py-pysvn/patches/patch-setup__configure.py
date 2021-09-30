$NetBSD: patch-setup__configure.py,v 1.1 2021/09/30 16:15:10 hauke Exp $

Add support for NetBSD toolchain.

--- setup_configure.py.orig	2021-09-29 20:38:06.063225727 +0000
+++ setup_configure.py
@@ -184,6 +184,9 @@ class Setup:
             elif sys.platform.startswith('freebsd'):
                 self.platform = 'freebsd'
 
+            elif sys.platform.startswith('netbsd'):
+                self.platform = 'netbsd'
+
             elif sys.platform == 'cygwin':
                 self.platform = 'cygwin'
 
@@ -214,6 +217,10 @@ class Setup:
             self.c_utils = FreeBsdCompilerGCC( self )
             self.c_pysvn = FreeBsdCompilerGCC( self )
 
+        elif self.platform == 'netbsd':
+            self.c_utils = NetBsdCompilerGCC( self )
+            self.c_pysvn = NetBsdCompilerGCC( self )
+
         elif self.platform == 'cygwin':
             self.c_utils = CygwinCompilerGCC( self )
             self.c_pysvn = CygwinCompilerGCC( self )
@@ -1348,6 +1355,31 @@ class FreeBsdCompilerGCC(UnixCompilerGCC
                 ] )
         return py_ld_libs
 
+class NetBsdCompilerGCC(UnixCompilerGCC):
+    def __init__( self, setup ):
+        UnixCompilerGCC.__init__( self, setup )
+
+    def _getLdLibs( self ):
+        py_ld_libs = [
+                '-L%(SVN_LIB)s',
+                '-L%(APR_LIB)s',
+                '-Wl,-R',
+                '-Wl,@PREFIX@/lib',
+                '-lsvn_client-1',
+                '-lsvn_diff-1',
+                '-lsvn_repos-1',
+                ]
+
+        if os.path.exists( '/usr/lib/libkrb5.so' ):
+            py_ld_libs.append( '-lkrb5' )
+
+        py_ld_libs.extend( [
+                '-lcom_err',
+                '-lexpat',
+                '-lneon',
+                ] )
+        return py_ld_libs
+
 class CygwinCompilerGCC(UnixCompilerGCC):
     def __init__( self, setup ):
         UnixCompilerGCC.__init__( self, setup )
