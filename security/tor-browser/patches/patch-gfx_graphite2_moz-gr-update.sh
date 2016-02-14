$NetBSD: patch-gfx_graphite2_moz-gr-update.sh,v 1.1 2016/02/14 07:30:54 ryoon Exp $

--- gfx/graphite2/moz-gr-update.sh.orig	2014-11-21 03:37:30.000000000 +0000
+++ gfx/graphite2/moz-gr-update.sh
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
 
