$NetBSD: patch-libgo_mksysinfo.sh,v 1.1 2015/07/16 12:03:36 ryoon Exp $

--- libgo/mksysinfo.sh.orig	2014-11-12 07:15:40.000000000 +0000
+++ libgo/mksysinfo.sh
@@ -470,7 +470,7 @@ upcase_fields () {
 # GNU/Linux specific; it should do no harm if there is no
 # _user_regs_struct.
 regs=`grep '^type _user_regs_struct struct' gen-sysinfo.go || true`
-if test "$regs" == ""; then
+if test "$regs" = ""; then
   # s390
   regs=`grep '^type __user_regs_struct struct' gen-sysinfo.go || true`
   if test "$regs" != ""; then
