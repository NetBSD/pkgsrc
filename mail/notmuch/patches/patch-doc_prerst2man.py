$NetBSD: patch-doc_prerst2man.py,v 1.1 2014/07/03 15:01:46 wiz Exp $

--- doc/prerst2man.py.orig	2014-05-06 07:27:29.000000000 +0000
+++ doc/prerst2man.py
@@ -59,5 +59,5 @@ for page in man_pages:
     outfile.write("".join(lines))
     outfile.close()
 
-    system('set -x; rst2man {0} {1}/{2}.{3}'
+    system('set -x; rst2man.py {0} {1}/{2}.{3}'
            .format(filename, outdir, page[0], page[4]))
