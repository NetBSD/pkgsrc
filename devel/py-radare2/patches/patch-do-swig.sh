$NetBSD: patch-do-swig.sh,v 1.1 2015/11/16 01:31:10 khorben Exp $

valabind-cc only accepts "-L" and "-l" through pkg-config.

--- do-swig.sh.orig	2015-07-08 23:27:21.000000000 +0000
+++ do-swig.sh
@@ -16,7 +16,7 @@ cd ${LNG}
 
 #valabind-cc ${LNG} ${MOD} -I../../libr/include ../../libr/vapi/${MOD}.vapi -l${MOD} -L../../libr/$(echo ${MOD} | sed -e s,r_,,)
 
-echo "Build ${MOD} `pkg-config --libs ${MOD}`"
+echo "Build ${MOD} `pkg-config --libs-only-L --libs-only-l ${MOD}`"
 
 case "${LNG}" in
 *node*|ctypes)
@@ -48,8 +48,8 @@ export PYTHON_CONFIG
 echo valabind-cc ${LNG} ${MOD} ${VALABINDFLAGS} \
 	-NRadare -NSDB ${VBMODE} \
 	-x --vapidir=../vapi ../vapi/${MOD} \
-	`pkg-config --cflags --libs ${MOD}`
+	`pkg-config --cflags --libs-only-L --libs-only-l ${MOD}`
 exec valabind-cc ${LNG} ${MOD} ${VALABINDFLAGS} \
 	-NRadare -NSDB ${VBMODE} \
 	-x --vapidir=../vapi ../vapi/${MOD} \
-	`pkg-config --cflags --libs ${MOD}`
+	`pkg-config --cflags --libs-only-L --libs-only-l ${MOD}`
