$NetBSD: patch-deps_cares_cares.gyp,v 1.2 2019/08/03 07:31:15 adam Exp $

Add support for NetBSD.

--- deps/cares/cares.gyp.orig	2013-03-14 10:55:24.000000000 +0900
+++ deps/cares/cares.gyp	2013-03-14 10:55:47.000000000 +0900
@@ -140,6 +140,10 @@
           'include_dirs': [ 'config/freebsd' ],
           'sources': [ 'config/freebsd/ares_config.h' ]
         }],
+        [ 'OS=="netbsd"', {
+          'include_dirs': [ 'config/netbsd' ],
+          'sources': [ 'config/netbsd/ares_config.h' ]
+        }],
         [ 'OS=="openbsd"', {
           'include_dirs': [ 'config/openbsd' ],
           'sources': [ 'config/openbsd/ares_config.h' ]
