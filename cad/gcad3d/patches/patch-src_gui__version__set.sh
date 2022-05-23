$NetBSD: patch-src_gui__version__set.sh,v 1.1 2022/05/23 19:10:03 plunky Exp $

we are neither deb or rpm; enable pkg-config to find gtk

--- src/gui_version_set.sh.orig	2020-11-16 07:09:05.000000000 +0000
+++ src/gui_version_set.sh
@@ -15,14 +15,7 @@ echo "instTyp = |"${instTyp}"|"
 
 
 if [ $1 = "gtk2" ] ; then
-  if [ ${instTyp} = "deb" ] ; then
-    if [ -z "`dpkg -l | grep libgtk2.0-dev`" ] ; then
-       echo "**** gui_version_set.sh ERROR gtk2 not installed"
-       exit 1
-    fi
-  else
-#   if [ -z "`pkg-config --list-all | grep gtk+-2.0`" ] ; then
-    if [ -z "`rpm -qa | grep gtk2-dev`" ] ; then
+    if [ -z "`pkg-config --list-all | grep gtk+-2.0`" ] ; then
        echo "**** gui_version_set.sh ERROR gtk2 not installed"
        exit 1
     fi
@@ -33,14 +26,7 @@ fi
 
 
 if [ $1 = "gtk3" ] ; then
-  if [ ${instTyp} = "deb" ] ; then
-    if [ -z "`dpkg -l | grep libgtk-3-dev`" ] ; then
-       echo "**** gui_version_set.sh ERROR gtk3 not installed"
-       exit 1
-    fi
-  else
-#   if [ -z "`pkg-config --list-all | grep gtk+-3.0`" ] ; then
-    if [ -z "`rpm -qa | grep gtk3-dev`" ] ; then
+    if [ -z "`pkg-config --list-all | grep gtk+-3.0`" ] ; then
        echo "**** gui_version_set.sh ERROR gtk3 not installed"
        exit 1
     fi
