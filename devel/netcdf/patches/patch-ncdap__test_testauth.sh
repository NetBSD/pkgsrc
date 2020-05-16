$NetBSD: patch-ncdap__test_testauth.sh,v 1.3 2020/05/16 21:19:58 gdt Exp $

Portability fix.

\todo File upstream.

--- ncdap_test/testauth.sh.orig	2018-03-15 21:22:57.000000000 +0000
+++ ncdap_test/testauth.sh
@@ -87,7 +87,7 @@ createrc() {
   RCP="$1" ; shift
   unset NOPWD
   unset BADPWD
-  while [[ $# > 0 ]] ; do
+  while [ "$#" > 0 ] ; do
     case "$1" in
     nopwd) NOPWD=1 ;;
     badpwd) BADPWD=1 ;;
@@ -124,7 +124,7 @@ createnetrc() {
   NCP="$1" ; shift
   unset NOPWD
   unset BADPWD
-  while [[ $# > 0 ]] ; do
+  while [ "$#" > 0 ] ; do
     case "$1" in
     nopwd) NOPWD=1 ;;
     badpwd) BADPWD=1 ;;
@@ -246,7 +246,7 @@ if test "x$RCHOME" = x1 ; then
   show
 fi
 
-if test "x$RCSPEC" == x1 ; then
+if test "x$RCSPEC" = x1 ; then
   echo "*** Testing rc file in specified directory"
   # Create the rc file and (optional) netrc file
   reset
