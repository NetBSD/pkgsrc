$NetBSD: patch-tests_misc_b2sum.sh,v 1.1 2022/07/27 14:32:37 ryoon Exp $

* Fix POSIX shell portability issue.

--- tests/misc/b2sum.sh.orig	2022-04-11 15:59:13.000000000 +0000
+++ tests/misc/b2sum.sh
@@ -41,7 +41,7 @@ $prog --strict -c openssl.b2sum || fail=
 rm -f check.vals || framework_failure_
 # Ensure we can check non tagged format
 [ "$prog" != 'b2sum' ] && tag_opt='--untagged' || tag_opt=''
-[ "$prog" == 'b2sum' ] && text_opt='--text' || text_opt=''
+[ "$prog" = 'b2sum' ] && text_opt='--text' || text_opt=''
 for l in 0 128; do
   $prog $tag_opt $text_opt -l $l /dev/null | tee -a check.vals > check.b2sum
   $prog -l $l --strict -c check.b2sum || fail=1
