$NetBSD: patch-scripts_check__jni__methods.sh,v 1.1 2021/12/27 05:28:38 dholland Exp $

Remove wrong escape that now fails.

--- scripts/check_jni_methods.sh~	2006-09-27 18:36:09.000000000 +0000
+++ scripts/check_jni_methods.sh
@@ -25,7 +25,7 @@ find native/jni -name \*.cpp | \
 find native/jni -name \*.cpp | \
 	xargs egrep -h '^(JNIEXPORT .* JNICALL )?Java_' | \
 	cut -f4 -d\  | \
-        LC_ALL=C sed -e 's,^\JNIEXPORT .* JNICALL \(Java_[a-z_A-Z0-9]*\) *(.*$,\1,' >> $TMPFILE2
+        LC_ALL=C sed -e 's,^JNIEXPORT .* JNICALL \(Java_[a-z_A-Z0-9]*\) *(.*$,\1,' >> $TMPFILE2
 mv $TMPFILE2 $TMPFILE3
 sort $TMPFILE3 | uniq > $TMPFILE2
 rm $TMPFILE3
