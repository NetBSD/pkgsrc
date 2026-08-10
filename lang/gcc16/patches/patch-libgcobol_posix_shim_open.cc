$NetBSD: patch-libgcobol_posix_shim_open.cc,v 1.1 2026/08/10 21:41:35 wiz Exp $

Guard Linux-specific open(2) flags (O_DIRECT, O_LARGEFILE, O_NOATIME,
O_PATH, O_TMPFILE) with #ifdef so libgcobol builds on NetBSD, where
these flags are not defined.


--- libgcobol/posix/shim/open.cc.ORIG	2026-04-30 09:33:28.000000000 +0100
+++ libgcobol/posix/shim/open.cc	2026-05-11 11:31:52.302652073 +0100
@@ -29,15 +29,25 @@
     { cbl::PSX_O_APPEND, O_APPEND },
     { cbl::PSX_O_NONBLOCK, O_NONBLOCK },
     { cbl::PSX_O_DSYNC, O_DSYNC },
+#ifdef O_DIRECT
     { cbl::PSX_O_DIRECT, O_DIRECT },
+#endif
+#ifdef O_LARGEFILE
     { cbl::PSX_O_LARGEFILE, O_LARGEFILE },
+#endif
     { cbl::PSX_O_DIRECTORY, O_DIRECTORY },
     { cbl::PSX_O_NOFOLLOW, O_NOFOLLOW },
+#ifdef O_NOATIME
     { cbl::PSX_O_NOATIME, O_NOATIME },
+#endif
     { cbl::PSX_O_CLOEXEC, O_CLOEXEC },
     { cbl::PSX_O_SYNC, O_SYNC },
+#ifdef O_PATH
     { cbl::PSX_O_PATH, O_PATH },
+#endif
+#ifdef O_TMPFILE
     { cbl::PSX_O_TMPFILE, O_TMPFILE },
+#endif
   };
 
   static const std::map<int, int> mode_bits {
