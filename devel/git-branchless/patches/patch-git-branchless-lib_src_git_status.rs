$NetBSD: patch-git-branchless-lib_src_git_status.rs,v 1.1 2023/04/26 11:36:25 wiz Exp $

Necessary because of pkgsrc patch to use newer git2-rs.

--- git-branchless-lib/src/git/status.rs.orig	2023-03-17 17:20:34.000000000 +0000
+++ git-branchless-lib/src/git/status.rs
@@ -81,6 +81,7 @@ impl From<git2::FileMode> for FileMode {
             git2::FileMode::Link => FileMode::Link,
             git2::FileMode::Tree => FileMode::Tree,
             git2::FileMode::Unreadable => FileMode::Unreadable,
+            git2::FileMode::BlobGroupWritable => todo!(),
         }
     }
 }
