$NetBSD: patch-node__modules_bin-links_lib_man-target.js,v 1.1 2022/04/11 18:50:31 adam Exp $

Use PKGMANDIR.

--- node_modules/bin-links/lib/man-target.js.orig	2022-03-31 22:14:06.000000000 +0000
+++ node_modules/bin-links/lib/man-target.js
@@ -3,4 +3,4 @@ const getPrefix = require('./get-prefix.
 const { dirname } = require('path')
 
 module.exports = ({ top, path }) => !top || isWindows ? null
-  : dirname(getPrefix(path)) + '/share/man'
+  : '@DESTDIR@@PREFIX@/@PKGMANDIR@'
