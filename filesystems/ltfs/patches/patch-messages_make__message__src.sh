$NetBSD: patch-messages_make__message__src.sh,v 1.2 2021/01/23 13:17:00 mef Exp $

date: 2020-05-15 05:08:30 +0900;  author: joerg;  state: Exp;  commitid: gg4PmA6YBrH0nf8C;
Replace internal .libs copy of the static archive after modification.
Still not MAKE_JOBS_SAFE, but at least it finally builds consistently.

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
