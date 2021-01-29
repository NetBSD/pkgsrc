$NetBSD: patch-regress_cmdline_histedit.sh,v 1.1 2021/01/29 20:35:11 ryoon Exp $

--- regress/cmdline/histedit.sh.orig	2020-12-13 15:08:45 UTC
+++ regress/cmdline/histedit.sh
@@ -1468,7 +1468,7 @@ test_histedit_fold_only() {
 
 	cat > $testroot/editor.sh <<EOF
 #!/bin/sh
-sed -i 's/.*/committing folded changes/' "\$1"
+sed -i '' 's/.*/committing folded changes/' "\$1"
 EOF
 	chmod +x $testroot/editor.sh
 
@@ -1584,7 +1584,7 @@ test_histedit_fold_only_empty_logmsg() {
 
 	cat > $testroot/editor.sh <<EOF
 #!/bin/sh
-sed -i 'd' "\$1"
+sed -i '' 'd' "\$1"
 EOF
 	chmod +x $testroot/editor.sh
 
