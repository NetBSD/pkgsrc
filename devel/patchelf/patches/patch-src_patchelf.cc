$NetBSD: patch-src_patchelf.cc,v 1.1 2026/11/11 13:38:36 pho Exp $

Fix for SunOS: There is no section ".gnu.version_r" on this platform. The
corresponding section is ".SUNW_version".

TODO: Test this more thoroughly and then send a pull request to the
upstream.

--- src/patchelf.cc.orig	1970-01-01 00:00:01.000000000 +0000
+++ src/patchelf.cc
@@ -1425,8 +1425,12 @@ void ElfFile<ElfFileParamNames>::rewrite
                 if (!shdr) continue;
                 dyn->d_un.d_ptr = (*shdr).get().sh_addr;
             }
-            else if (d_tag == DT_VERNEED)
-                dyn->d_un.d_ptr = findSectionHeader(".gnu.version_r").sh_addr;
+            else if (d_tag == DT_VERNEED) {
+                auto shdr = tryFindSectionHeader(".gnu.version_r");
+                if (!shdr) shdr = tryFindSectionHeader(".SUNW_version");
+                if (!shdr) error("cannot find section corresponding to DT_VERNEED");
+                dyn->d_un.d_ptr = (*shdr).get().sh_addr;
+            }
             else if (d_tag == DT_VERDEF)
                 dyn->d_un.d_ptr = findSectionHeader(".gnu.version_d").sh_addr;
             else if (d_tag == DT_VERSYM)
