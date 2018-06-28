$NetBSD: patch-lib_config_defaults.js,v 1.1 2018/06/28 11:28:01 fhajny Exp $

If both PREFIX and DESTDIR are defined, combine for UNIX best practice.

--- lib/config/defaults.js.orig	2018-05-24 01:48:32.000000000 +0000
+++ lib/config/defaults.js
@@ -91,6 +91,9 @@ Object.defineProperty(exports, 'defaults
 
   if (process.env.PREFIX) {
     globalPrefix = process.env.PREFIX
+    if (process.env.DESTDIR) {
+      globalPrefix = path.join(process.env.DESTDIR, globalPrefix)
+    }
   } else if (process.platform === 'win32') {
     // c:\node\node.exe --> prefix=c:\node\
     globalPrefix = path.dirname(process.execPath)
