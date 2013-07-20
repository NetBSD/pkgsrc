$NetBSD: patch-acinclude.m4,v 1.1 2013/07/20 05:10:42 richard Exp $

Fix LDFLAGS problem for sun ld not supporting -as-needed

--- acinclude.m4.orig	2012-08-02 14:28:51.000000000 +0000
+++ acinclude.m4
@@ -684,7 +684,9 @@ AC_DEFUN([SETUP_POSTGRESQL],
 			case "${host}" in
 				*-apple-darwin*)
 					;;
- 
+                                *solaris*)
+                                        LDFLAGS="$LDFLAGS"
+                                        ;;
 				*)
 					LDFLAGS="$LDFLAGS -Wl,-as-needed"
 					;;
