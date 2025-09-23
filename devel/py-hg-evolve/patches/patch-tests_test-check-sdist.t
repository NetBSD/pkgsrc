$NetBSD: patch-tests_test-check-sdist.t,v 1.1 2025/09/23 00:27:13 joerg Exp $

BSD wc left-pads the number.

--- tests/test-check-sdist.t.orig	2025-07-25 16:21:02.000000000 +0000
+++ tests/test-check-sdist.t
@@ -39,9 +39,9 @@ Archiving to a separate location to avoi
   $ grep -E '^tests/test-.*\.(t|py)$' ../files > ../test-files
   $ grep -E -v '^tests/test-.*\.(t|py)$' ../files > ../other-files
   $ wc -l ../other-files
-  ??? ../other-files (glob)
+  [ \t]*[0-9][0-9][0-9] ../other-files (re)
   $ wc -l ../test-files
-  ??? ../test-files (glob)
+  [ \t]*[0-9][0-9][0-9] ../test-files (re)
   $ grep -F debian ../files
   tests/test-check-debian.t
   $ grep -F __init__.py ../files
