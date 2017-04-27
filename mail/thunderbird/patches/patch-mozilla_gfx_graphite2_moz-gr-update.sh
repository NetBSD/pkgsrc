$NetBSD: patch-mozilla_gfx_graphite2_moz-gr-update.sh,v 1.3 2017/04/27 13:32:40 ryoon Exp $

--- mozilla/gfx/graphite2/moz-gr-update.sh.orig	2017-04-14 04:53:08.000000000 +0000
+++ mozilla/gfx/graphite2/moz-gr-update.sh
@@ -1,6 +1,7 @@
 #!/bin/bash
 
 # Script used to update the Graphite2 library in the mozilla source tree
+# and bump version for --with-system-graphite2
 
 # This script lives in gfx/graphite2, along with the library source,
 # but must be run from the top level of the mozilla-central tree.
@@ -37,12 +38,16 @@ echo "See" $0 "for update procedure." >>
 #find gfx/graphite2/ -name "*.cpp" -exec perl -p -i -e "s/<cstdio>/<stdio.h>/;s/Windows.h/windows.h/;" {} \;
 #find gfx/graphite2/ -name "*.h" -exec perl -p -i -e "s/<cstdio>/<stdio.h>/;s/Windows.h/windows.h/;" {} \;
 
+# chase version for --with-system-graphite2
+perl -p -i -e "s/[0-9]+\,[0-9]+\,[0-9]+/$RELEASE/ and tr/./,/ \
+  if /GR2_VERSION_REQUIRE/" old-configure.in
+
 # summarize what's been touched
 echo Updated to $RELEASE.
 echo Here is what changed in the gfx/graphite2 directory:
 echo
 
-hg stat gfx/graphite2
+hg stat old-configure.in gfx/graphite2
 
 echo
 echo If gfx/graphite2/src/files.mk has changed, please make corresponding
