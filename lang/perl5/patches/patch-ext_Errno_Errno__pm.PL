$NetBSD: patch-ext_Errno_Errno__pm.PL,v 1.3 2021/03/15 14:23:12 ryoon Exp $

* Fix build under Haiku R1/beta2.

--- ext/Errno/Errno_pm.PL.orig	2020-12-18 10:04:36.000000000 +0000
+++ ext/Errno/Errno_pm.PL
@@ -143,7 +143,7 @@ sub get_files {
 	$file{$linux_errno_h} = 1;
     } elsif ($^O eq 'haiku') {
 	# hidden in a special place
-	$file{'/boot/develop/headers/posix/errno.h'} = 1;
+	$file{'/boot/system/develop/headers/posix/errno.h'} = 1;
 
     } elsif ($^O eq 'vos') {
 	# avoid problem where cpp returns non-POSIX pathnames
