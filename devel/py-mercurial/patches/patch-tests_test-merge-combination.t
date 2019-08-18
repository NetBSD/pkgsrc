$NetBSD: patch-tests_test-merge-combination.t,v 1.1 2019/08/18 08:35:47 wiz Exp $

Fix test case on *BSD.
https://phab.mercurial-scm.org/D6729

--- tests/test-merge-combination.t.orig	2019-08-01 16:14:49.000000000 +0000
+++ tests/test-merge-combination.t
@@ -57,7 +57,7 @@ revision. "C" indicates that hg merge ha
   >                fi
   >           else expected=a
   >           fi
-  >           got=`hg log -r 3 --template '{files}\n' | tr --delete 'e '`
+  >           got=`hg log -r 3 --template '{files}\n' | tr -d 'e '`
   >           if [ "$got" = "$expected" ]
   >           then echo "$line$conflicts: agree on \"$got\""
   >           else echo "$line$conflicts: hg said \"$got\", expected \"$expected\""
