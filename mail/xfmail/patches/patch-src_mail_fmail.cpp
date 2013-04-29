$NetBSD: patch-src_mail_fmail.cpp,v 1.1 2013/04/29 21:23:24 joerg Exp $

--- src/mail/fmail.cpp.orig	2013-04-29 19:31:08.000000000 +0000
+++ src/mail/fmail.cpp
@@ -1686,7 +1686,7 @@ compare_msgs(struct _mail_msg **msg1, st
 }
 
 unsigned long
-hash(const char *name) {
+my_hash(const char *name) {
 	unsigned long key = 0;
 	unsigned char c;
 
@@ -1791,7 +1791,7 @@ sort_folder(struct _mail_folder *folder)
 
 			if(m_id &&
 			   ((s = strchr(m_id->f_line,'<')) != NULL)) {
-				unsigned long key = hash(s) % htsize;
+				unsigned long key = my_hash(s) % htsize;
 				make_entry(ht, key, htsize, s, msg);
 			}
 			msg->ref = NULL;
@@ -1808,13 +1808,13 @@ sort_folder(struct _mail_folder *folder)
 			ref=NULL;
 			m_id = find_field(msg,"In-Reply-To");
 			if(m_id && (s=strrchr(m_id->f_line,'<'))) {
-				key = hash(s) % htsize;
+				key = my_hash(s) % htsize;
 				ref = find_entry(ht, key, htsize, s);
 			}
 			if(!ref) {
 				m_id=find_field(msg,"References");
 				if(m_id && (s=strrchr(m_id->f_line,'<'))) {
-					key = hash(s) % htsize;
+					key = my_hash(s) % htsize;
 					ref = find_entry(ht, key, htsize, s);
 				}
 			}
