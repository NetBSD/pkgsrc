$NetBSD: patch-include_ptlib_critsec.h,v 1.1 2015/06/29 21:13:30 markd Exp $

--- include/ptlib/critsec.h.orig	2012-08-23 02:13:00.000000000 +0000
+++ include/ptlib/critsec.h
@@ -40,7 +40,7 @@
 #if P_HAS_ATOMIC_INT
 
 #if defined(__GNUC__)
-#  if __GNUC__ >= 4 && __GNUC_MINOR__ >= 2
+#  if (__GNUC__ >= 4 && __GNUC_MINOR__ >= 2) || __GNUC__ >= 5 
 #     include <ext/atomicity.h>
 #  else
 #     include <bits/atomicity.h>
