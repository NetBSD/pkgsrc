$NetBSD: patch-sysupgrade.sh,v 1.1 2017/03/20 00:25:35 maya Exp $

Don't reject https

--- sysupgrade.sh.orig	2013-07-28 21:27:57.000000000 +0000
+++ sysupgrade.sh
@@ -199,7 +199,7 @@ sysupgrade_fetch() {
     fi
 
     case "${releasedir}" in
-        ftp://*|http://*)
+        ftp://*|http://*|https://*)
             mkdir -p "${cachedir}"
 
             for relative_file in ${fetch_files}; do
