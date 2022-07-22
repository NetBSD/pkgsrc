$NetBSD: patch-deps.sh,v 1.1 2022/07/22 20:17:14 wiz Exp $

* don't require git

--- deps.sh.orig	2021-10-04 18:02:44.000000000 +0000
+++ deps.sh
@@ -57,16 +57,6 @@ download_github() {
 
 
 main() {
-  if git -C "${MYDIR}" rev-parse; then
-    cat >&2 <<EOF
-Current directory is a git repository, downloading dependencies via git:
-
-  git submodule update --init --recursive
-
-EOF
-    git -C "${MYDIR}" submodule update --init --recursive
-    return 0
-  fi
 
   # Sources downloaded from a tarball.
   download_github third_party/highway google/highway
