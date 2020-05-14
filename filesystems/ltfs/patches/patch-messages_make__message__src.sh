$NetBSD: patch-messages_make__message__src.sh,v 1.1 2020/05/14 20:08:30 joerg Exp $

--- messages/make_message_src.sh.orig	2020-05-13 20:13:12.288742533 +0000
+++ messages/make_message_src.sh
@@ -89,6 +89,7 @@ make_obj() {
 			echo "pic_object='.libs/${OBJFILE}'" >> ${LTFILE}
 			echo "non_pic_object=none" >> ${LTFILE}
 			libtool --mode=link --tag=CC cc -o ../../lib${BASENAME}_dat.la ${LTFILE}
+			cp ../../lib${BASENAME}_dat.a ../../.libs/lib${BASENAME}_dat.a
 			;;
 		*)
 			mv ${BASENAME}_dat.o ../../lib${BASENAME}_dat.a
