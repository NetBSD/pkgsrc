$NetBSD: patch-chirp_platform.py,v 1.3 2023/08/28 10:37:40 gdt Exp $

Don't look for share other than in the right place.
\todo File upstream.
\todo Make upstream respect a configured share dir.

--- chirp/platform.py.orig	2023-02-23 10:01:01.000000000 +0000
+++ chirp/platform.py
@@ -117,10 +117,7 @@ class Platform:
         """Searches for files installed to a share/ prefix."""
         execpath = self.executable_path()
         share_candidates = [
-            os.path.join(execpath, "share"),
             os.path.join(sys.prefix, "share"),
-            "/usr/local/share",
-            "/usr/share",
         ]
         pkgshare_candidates = [os.path.join(i, "chirp")
                                for i in share_candidates]
