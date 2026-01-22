$NetBSD: patch-comm_third__party_rust_dogear_.github_workflows_upload-to-codecov.sh,v 1.1 2026/01/22 19:41:09 ryoon Exp $

--- comm/third_party/rust/dogear/.github/workflows/upload-to-codecov.sh.orig	2026-01-14 09:59:10.661689958 +0000
+++ comm/third_party/rust/dogear/.github/workflows/upload-to-codecov.sh
@@ -37,7 +37,7 @@ mc=
 
 # actions/checkout runs in detached HEAD
 mc=
-if [ -n "$pr" ] && [ "$pr" != false ] && [ "$commit_o" == "" ];
+if [ -n "$pr" ] && [ "$pr" != false ] && [ "$commit_o" = "" ];
 then
   mc=$(git show --no-patch --format="%P" 2>/dev/null || echo "")
 
