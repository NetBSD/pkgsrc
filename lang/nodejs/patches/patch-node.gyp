$NetBSD: patch-node.gyp,v 1.1 2016/10/13 14:09:12 fhajny Exp $

Backport system zlib fix from upstream master.
https://github.com/nodejs/node/pull/9077

--- node.gyp.orig	2016-10-12 19:04:28.000000000 +0000
+++ node.gyp
@@ -477,6 +477,8 @@
         }],
         [ 'node_shared_zlib=="false"', {
           'dependencies': [ 'deps/zlib/zlib.gyp:zlib' ],
+        }, {
+          'defines': [ 'ZLIB_CONST' ],
         }],
 
         [ 'node_shared_http_parser=="false"', {
