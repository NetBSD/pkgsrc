$NetBSD: patch-__des.h,v 1.1 2025/07/08 13:25:51 jperkin Exp $

https://rt.cpan.org/Public/Bug/Display.html?id=133363

--- _des.h.orig	2025-07-08 13:23:58.175430211 +0000
+++ _des.h
@@ -5,3 +5,5 @@ typedef unsigned long des_ks[32];
 void _des_crypt( des_cblock in, des_cblock out, des_ks key, int encrypt );
 void _des_expand_key( des_user_key userKey, des_ks key );
 
+void perl_des_expand_key(des_user_key userKey, des_ks ks);
+void perl_des_crypt( des_cblock input, des_cblock output, des_ks ks, int encrypt );
