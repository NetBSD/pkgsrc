$NetBSD: patch-noreturn.h,v 1.1 2012/12/21 04:23:45 dholland Exp $

Place attribute noreturn where recent gcc wants it.

--- noreturn.h~	1999-02-09 05:05:17.000000000 +0000
+++ noreturn.h
@@ -12,7 +12,12 @@
 
 # if defined (__GNUC__) && defined (__GNUC_MINOR__)
 
-# if __GNUC__ >= 2 && __GNUC_MINOR__ >= 5
+# if __GNUC__ >= 4
+
+# define NORETURN __attribute__ ((noreturn))
+# define NRUTERON
+
+# elif __GNUC__ >= 2 && __GNUC_MINOR__ >= 5
 
 # define NORETURN
 # define NRUTERON __attribute__ ((noreturn))
