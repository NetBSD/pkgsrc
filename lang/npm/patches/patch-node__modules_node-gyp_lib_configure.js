$NetBSD: patch-node__modules_node-gyp_lib_configure.js,v 1.2 2019/08/03 07:32:55 adam Exp $

Skip Python detection, version 2.7 is required and we know where it is.

--- node_modules/node-gyp/lib/configure.js.orig	2019-07-23 16:20:30.000000000 +0000
+++ node_modules/node-gyp/lib/configure.js
@@ -15,21 +15,14 @@ if (win) {
 }
 
 function configure (gyp, argv, callback) {
-  var python
+  var python = '@PYTHONBIN@'
   var buildDir = path.resolve('build')
   var configNames = [ 'config.gypi', 'common.gypi' ]
   var configs = []
   var nodeDir
   var release = processRelease(argv, gyp, process.version, process.release)
 
-  findPython(gyp.opts.python, function (err, found) {
-    if (err) {
-      callback(err)
-    } else {
-      python = found
-      getNodeDir()
-    }
-  })
+  getNodeDir()
 
   function getNodeDir () {
     // 'python' should be set by now
