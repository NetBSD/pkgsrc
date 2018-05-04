$NetBSD: patch-node__modules_node-gyp_lib_configure.js,v 1.1 2018/05/04 13:23:53 fhajny Exp $

Skip Python detection, version 2.7 is required and we know where it is.

--- node_modules/node-gyp/lib/configure.js.orig	2018-04-24 05:41:37.000000000 +0000
+++ node_modules/node-gyp/lib/configure.js
@@ -29,21 +29,14 @@ exports.usage = 'Generates ' + (win ? 'M
 
 function configure (gyp, argv, callback) {
 
-  var python = gyp.opts.python || process.env.PYTHON || 'python2'
+  var python = '@PYTHONBIN@'
     , buildDir = path.resolve('build')
     , configNames = [ 'config.gypi', 'common.gypi' ]
     , configs = []
     , nodeDir
     , release = processRelease(argv, gyp, process.version, process.release)
 
-  findPython(python, function (err, found) {
-    if (err) {
-      callback(err)
-    } else {
-      python = found
-      getNodeDir()
-    }
-  })
+  getNodeDir()
 
   function getNodeDir () {
 
