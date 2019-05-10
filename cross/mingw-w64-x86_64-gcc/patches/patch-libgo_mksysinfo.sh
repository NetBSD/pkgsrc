$NetBSD: patch-libgo_mksysinfo.sh,v 1.1 2019/05/10 19:30:04 ryoon Exp $

--- libgo/mksysinfo.sh.orig	2019-03-19 14:00:59.000000000 +0000
+++ libgo/mksysinfo.sh
@@ -1127,7 +1127,7 @@ grep '^const _FALLOC_' gen-sysinfo.go |
 # Prefer largefile variant if available.
 # CentOS 5 does not have f_flags, so pull from f_spare.
 statfs=`grep '^type _statfs64 ' gen-sysinfo.go || true`
-if test "$statfs" == ""; then
+if test "$statfs" = ""; then
   statfs=`grep '^type _statfs ' gen-sysinfo.go || true`
 fi
 if ! echo "$statfs" | grep f_flags; then
