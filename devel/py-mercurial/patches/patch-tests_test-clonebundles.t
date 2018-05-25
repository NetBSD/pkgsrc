$NetBSD: patch-tests_test-clonebundles.t,v 1.1 2018/05/25 13:04:56 joerg Exp $

Merge 326b174c6a47 from upstream:
bundle2: mark the bundle2 part as advisory (issue5872)

--- tests/test-clonebundles.t.orig	2018-05-05 23:02:58.000000000 +0000
+++ tests/test-clonebundles.t
@@ -186,10 +186,10 @@ by old clients.
   0150: 88 75 34 36 75 04 82 55 17 14 36 a4 38 10 04 d8 |.u46u..U..6.8...|
   0160: 21 01 9a b1 83 f7 e9 45 8b d2 56 c7 a3 1f 82 52 |!......E..V....R|
   0170: d7 8a 78 ed fc d5 76 f1 36 25 81 89 c7 ad ec 90 |..x...v.6%......|
-  0180: 54 47 75 2b 89 48 b1 b2 62 ce 8e ce 1e ae 56 41 |TGu+.H..b.....VA|
-  0190: ae 61 ba 4e 41 8e 7e ce 1e ba 60 01 a0 14 23 58 |.a.NA.~...`...#X|
+  0180: 54 47 75 2b 89 48 b1 b2 62 c9 89 c9 19 a9 56 45 |TGu+.H..b.....VE|
+  0190: a9 65 ba 49 45 89 79 c9 19 ba 60 01 a0 14 23 58 |.e.IE.y...`...#X|
   01a0: 81 35 c8 7d 40 cc 04 e2 a4 a4 a6 25 96 e6 94 60 |.5.}@......%...`|
-  01b0: 33 17 5f 54 00 00 01 1b 0a ec                   |3._T......|
+  01b0: 33 17 5f 54 00 00 d3 1b 0d 4c                   |3._T.....L|
 
   $ echo "http://localhost:$HGPORT1/full.hg" > server/.hg/clonebundles.manifest
   $ hg clone -U http://localhost:$HGPORT full-bundle
@@ -530,14 +530,14 @@ Test clone bundle retrieved through bund
   $ cat hg.pid >> $DAEMON_PIDS
 
   $ hg -R server debuglfput gz-a.hg
-  14ee2f0b3f1d14aeeb2fe037e09fc295c3cf59f5
+  1f74b3d08286b9b3a16fb3fa185dd29219cbc6ae
 
   $ cat > server/.hg/clonebundles.manifest << EOF
-  > largefile://14ee2f0b3f1d14aeeb2fe037e09fc295c3cf59f5 BUNDLESPEC=gzip-v2
+  > largefile://1f74b3d08286b9b3a16fb3fa185dd29219cbc6ae BUNDLESPEC=gzip-v2
   > EOF
 
   $ hg clone -U http://localhost:$HGPORT largefile-provided --traceback
-  applying clone bundle from largefile://14ee2f0b3f1d14aeeb2fe037e09fc295c3cf59f5
+  applying clone bundle from largefile://1f74b3d08286b9b3a16fb3fa185dd29219cbc6ae
   adding changesets
   adding manifests
   adding file changes
