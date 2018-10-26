$NetBSD: patch-setup.py,v 1.1 2018/10/26 11:57:01 jperkin Exp $

Find libsqlite3.

--- setup.py.orig	2018-08-30 19:16:58.000000000 +0000
+++ setup.py
@@ -75,6 +75,7 @@ def _have_sqlite_extension_support():
         compiler.link_executable(
             compiler.compile([src_file], output_dir=tmp_dir),
             bin_file,
+            library_dirs=['@BUILDLINK_PREFIX.sqlite3@/lib'],
             libraries=['sqlite3'])
     except CCompilerError:
         print('unable to compile sqlite3 C extensions - missing headers?')
