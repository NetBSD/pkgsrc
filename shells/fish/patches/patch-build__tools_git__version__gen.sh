$NetBSD: patch-build__tools_git__version__gen.sh,v 1.1 2021/07/16 08:50:50 jperkin Exp $

Rename version file to avoid C++ <version> issue.

--- build_tools/git_version_gen.sh.orig	2021-07-06 14:45:37.000000000 +0000
+++ build_tools/git_version_gen.sh
@@ -12,9 +12,9 @@ DEF_VER=unknown
 
 # First see if there is a version file (included in release tarballs),
 # then try git-describe, then default.
-if test -f version
+if test -f version.txt
 then
-	VN=$(cat version) || VN="$DEF_VER"
+	VN=$(cat version.txt) || VN="$DEF_VER"
 elif ! VN=$(git -C "$FISH_BASE_DIR" describe --always --dirty 2>/dev/null); then
 	VN="$DEF_VER"
 fi
