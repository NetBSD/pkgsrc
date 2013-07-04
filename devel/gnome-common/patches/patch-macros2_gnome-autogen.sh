$NetBSD: patch-macros2_gnome-autogen.sh,v 1.2 2013/07/04 12:05:26 wiz Exp $

Add automake-1.13 support.

--- macros2/gnome-autogen.sh.orig	2012-10-15 22:58:19.000000000 +0000
+++ macros2/gnome-autogen.sh
@@ -346,14 +346,16 @@ AUTOHEADER=`echo $AUTOCONF | sed s/autoc
 
 case $REQUIRED_AUTOMAKE_VERSION in
     1.4*) automake_progs="automake-1.4" ;;
-    1.5*) automake_progs="automake-1.12 automake-1.11 automake-1.10 automake-1.9 automake-1.8 automake-1.7 automake-1.6 automake-1.5" ;;
-    1.6*) automake_progs="automake-1.12 automake-1.11 automake-1.10 automake-1.9 automake-1.8 automake-1.7 automake-1.6" ;;
-    1.7*) automake_progs="automake-1.12 automake-1.11 automake-1.10 automake-1.9 automake-1.8 automake-1.7" ;;
-    1.8*) automake_progs="automake-1.12 automake-1.11 automake-1.10 automake-1.9 automake-1.8" ;;
-    1.9*) automake_progs="automake-1.12 automake-1.11 automake-1.10 automake-1.9" ;;
-    1.10*) automake_progs="automake-1.12 automake-1.11 automake-1.10" ;;
-    1.11*) automake_progs="automake-1.12 automake-1.11" ;;
-    1.12*) automake_progs="automake-1.12" ;;
+    1.5*) automake_progs="automake-1.14 automake-1.13 automake-1.12 automake-1.11 automake-1.10 automake-1.9 automake-1.8 automake-1.7 automake-1.6 automake-1.5" ;;
+    1.6*) automake_progs="automake-1.14 automake-1.13 automake-1.12 automake-1.11 automake-1.10 automake-1.9 automake-1.8 automake-1.7 automake-1.6" ;;
+    1.7*) automake_progs="automake-1.14 automake-1.13 automake-1.12 automake-1.11 automake-1.10 automake-1.9 automake-1.8 automake-1.7" ;;
+    1.8*) automake_progs="automake-1.14 automake-1.13 automake-1.12 automake-1.11 automake-1.10 automake-1.9 automake-1.8" ;;
+    1.9*) automake_progs="automake-1.14 automake-1.13 automake-1.12 automake-1.11 automake-1.10 automake-1.9" ;;
+    1.10*) automake_progs="automake-1.14 automake-1.13 automake-1.12 automake-1.11 automake-1.10" ;;
+    1.11*) automake_progs="automake-1.14 automake-1.13 automake-1.12 automake-1.11" ;;
+    1.12*) automake_progs="automake-1.14 automake-1.13 automake-1.12" ;;
+    1.13*) automake_progs="automake-1.14 automake-1.13" ;;
+    1.14*) automake_progs="automake-1.14" ;;
 esac
 version_check automake AUTOMAKE "$automake_progs" $REQUIRED_AUTOMAKE_VERSION \
     "http://ftp.gnu.org/pub/gnu/automake/automake-$REQUIRED_AUTOMAKE_VERSION.tar.gz"
