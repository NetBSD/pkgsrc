$NetBSD: patch-mac_scripts_create__info__header.sh,v 1.1 2019/02/10 17:14:42 nia Exp $

Portability fix.

--- mac/scripts/create_info_header.sh.orig	2018-02-14 07:11:20.000000000 +0000
+++ mac/scripts/create_info_header.sh
@@ -21,7 +21,7 @@ done
 cd ${TOPLEVEL}
 mkdir -p mac/build
 eval $(g++ -E -dM src/Audacity.h | awk '/#define *AUDACITY_(VERSION|RELEASE|REVISION|MODLEVEL) /{print $2 "=" $3}')
-if [ $CONFIGURATION == 'Debug' ]
+if [ $CONFIGURATION = 'Debug' ]
 then
     AUDACITY_EXECUTABLE=Audacity
 else
