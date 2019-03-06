$NetBSD: patch-node__modules_bin-links_index.js,v 1.1 2019/03/06 09:42:09 maya Exp $

Install to PKGMANDIR.

--- node_modules/bin-links/index.js.orig	2019-02-13 23:14:36.000000000 +0000
+++ node_modules/bin-links/index.js
@@ -117,7 +117,7 @@ function linkBin (from, to, opts) {
 function linkMans (pkg, folder, parent, gtop, opts) {
   if (!pkg.man || !gtop || process.platform === 'win32') return
 
-  var manRoot = path.resolve(opts.prefix, 'share', 'man')
+  var manRoot = path.resolve(opts.prefix, '@PKGMANDIR@')
   opts.log.verbose('linkMans', 'man files are', pkg.man, 'in', manRoot)
 
   // make sure that the mans are unique.
