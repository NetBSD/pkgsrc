$NetBSD: patch-build__tools_git__version__gen.sh,v 1.2 2022/08/18 18:11:51 wiz Exp $

Rename version file to avoid C++ <version> issue.

--- build_tools/git_version_gen.sh.orig	2022-06-16 10:49:19.000000000 +0000
+++ build_tools/git_version_gen.sh
@@ -13,9 +13,9 @@ git_permission_failed=0
 
 # First see if there is a version file (included in release tarballs),
 # then try git-describe, then default.
-if test -f version
+if test -f version.txt
 then
-	VN=$(cat version) || VN="$DEF_VER"
+	VN=$(cat version.txt) || VN="$DEF_VER"
 else
     if VN=$(git -C "$FISH_BASE_DIR" describe --always --dirty 2>/dev/null); then
        :
