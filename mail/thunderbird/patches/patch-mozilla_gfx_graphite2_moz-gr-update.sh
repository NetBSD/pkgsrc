$NetBSD: patch-mozilla_gfx_graphite2_moz-gr-update.sh,v 1.1 2015/07/09 15:17:34 ryoon Exp $

--- mozilla/gfx/graphite2/moz-gr-update.sh.orig	2015-06-08 17:49:34.000000000 +0000
+++ mozilla/gfx/graphite2/moz-gr-update.sh
@@ -23,8 +23,14 @@ echo "\nSee" $0 "for update procedure.\n
 find gfx/graphite2/ -name "*.cpp" -exec perl -p -i -e "s/<cstdio>/<stdio.h>/;s/Windows.h/windows.h/;" {} \;
 find gfx/graphite2/ -name "*.h" -exec perl -p -i -e "s/<cstdio>/<stdio.h>/;s/Windows.h/windows.h/;" {} \;
 
+# closest tag/release to require for system version
+TAG=$(cd ../graphitedev/ && hg parents --template {latesttag})
+
+perl -p -i -e "s/[0-9]+\,[0-9]+\,[0-9]+/$TAG/ and tr/./,/ \
+  if /GR2_VERSION_REQUIRE/" configure.in
+
 # summarize what's been touched
-echo Updated to $CHANGESET.
+echo Updated to $CHANGESET \($TAG for --with-system-graphite2\)
 echo Here is what changed in the gfx/graphite2 directory:
 echo
 
