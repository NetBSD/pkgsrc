$NetBSD: patch-setup.py,v 1.3 2016/08/18 20:30:02 wiz Exp $

--- setup.py.orig	2016-07-03 11:46:48.000000000 +0000
+++ setup.py
@@ -793,23 +793,6 @@ if 'BLOSC' not in optional_libs:
         finally:
             os.remove(fd.name)
 
-    # Detection code for SSE2/AVX2 only works for gcc/clang, not for MSVC yet
-    # SSE2
-    if ('sse2' in cpu_info['flags'] and
-        compiler_has_flags(compiler, ["-msse2"])):
-        print('SSE2 detected')
-        CFLAGS.append('-DSHUFFLE_SSE2_ENABLED')
-        CFLAGS.append('-msse2')
-        blosc_sources += [f for f in glob.glob('c-blosc/blosc/*.c')
-                          if 'sse2' in f]
-    # AVX2
-    if ('avx2' in cpu_info['flags'] and
-        compiler_has_flags(compiler, ["-mavx2"])):
-        print('AVX2 detected')
-        CFLAGS.append('-DSHUFFLE_AVX2_ENABLED')
-        CFLAGS.append('-mavx2')
-        blosc_sources += [f for f in glob.glob('c-blosc/blosc/*.c')
-                          if 'avx2' in f]
 else:
     ADDLIBS += ['blosc']
 
