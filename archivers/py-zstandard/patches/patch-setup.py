$NetBSD: patch-setup.py,v 1.1 2017/09/23 18:25:51 wiedi Exp $

Don't pick up cffi by accident
--- setup.py.orig	2017-01-28 05:19:11.000000000 +0000
+++ setup.py
@@ -25,7 +25,7 @@ if "--legacy" in sys.argv:
 # facilitate reuse in other projects.
 extensions = [setup_zstd.get_c_extension(SUPPORT_LEGACY, 'zstd')]
 
-if cffi:
+if None:
     import make_cffi
     extensions.append(make_cffi.ffi.distutils_extension())
 
