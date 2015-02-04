$NetBSD: patch-qb_qb.libs.sh,v 1.1 2015/02/04 22:56:43 jmcneill Exp $

--- qb/qb.libs.sh.orig	2015-02-03 06:43:44.000000000 +0000
+++ qb/qb.libs.sh
@@ -17,7 +17,7 @@ add_include_dirs()
 {	while [ "$1" ]; do INCLUDE_DIRS="$INCLUDE_DIRS -I$1"; shift; done;}
 
 add_library_dirs()
-{	while [ "$1" ]; do LIBRARY_DIRS="$LIBRARY_DIRS -L$1"; shift; done;}
+{	while [ "$1" ]; do LIBRARY_DIRS="$LIBRARY_DIRS -Wl,-R$1 -L$1"; shift; done;}
 
 check_lib()	#$1 = HAVE_$1	$2 = lib	$3 = function in lib	$4 = extralibs $5 = headers
 {	tmpval="$(eval echo \$HAVE_$1)"
