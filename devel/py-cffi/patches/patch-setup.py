$NetBSD: patch-setup.py,v 1.2 2026/07/10 09:42:35 adam Exp $

Nope, we want the one from pkgsrc. Honour pkg-config.

Also, -iwithsysroot is not supported by all compilers.

--- setup.py.orig	2026-07-06 20:52:02.000000000 +0000
+++ setup.py
@@ -154,14 +154,6 @@ else:
     ask_supports_thread()
     ask_supports_sync_synchronize()
 
-if sysconfig.get_platform().startswith('macosx'):
-    # priority is given to `pkg_config`, but always fall back on SDK's libffi.
-    extra_compile_args += ['-iwithsysroot/usr/include/ffi']
-
-if 'freebsd' in sys.platform:
-    include_dirs.append('/usr/local/include')
-    library_dirs.append('/usr/local/lib')
-
 forced_extra_objs = os.environ.get('CFFI_FORCE_STATIC', [])
 if forced_extra_objs:
     forced_extra_objs = forced_extra_objs.split(';')
