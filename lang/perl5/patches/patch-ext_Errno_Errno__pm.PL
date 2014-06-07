$NetBSD: patch-ext_Errno_Errno__pm.PL,v 1.1 2014/06/07 11:57:34 obache Exp $

* add include path for Haiku new directory layout.

--- ext/Errno/Errno_pm.PL.orig	2014-05-26 13:34:20.000000000 +0000
+++ ext/Errno/Errno_pm.PL
@@ -142,6 +142,7 @@ sub get_files {
 	$file{$linux_errno_h} = 1;
     } elsif ($^O eq 'haiku') {
 	# hidden in a special place
+	$file{'/boot/system/develop/headers/posix/errno.h'} = 1;
 	$file{'/boot/develop/headers/posix/errno.h'} = 1;
 
     } elsif ($^O eq 'vos') {
