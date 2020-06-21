$NetBSD: patch-include_ntp__md5.h,v 1.1 2020/06/21 15:10:47 taca Exp $

* Changes from NetBSD base.

--- include/ntp_md5.h.orig	2018-08-14 11:51:07.000000000 +0000
+++ include/ntp_md5.h
@@ -36,8 +36,8 @@
 # define EVP_md5()			NULL
 # define EVP_MD_CTX_init(c)
 # define EVP_MD_CTX_set_flags(c, f)
-# define EVP_DigestInit(c, dt)		(MD5Init(c), 1)
-# define EVP_DigestInit_ex(c, dt, i)	(MD5Init(c), 1)
+# define EVP_DigestInit(c, dt)		(MD5Init(c), (dt ? 1 : 1))
+# define EVP_DigestInit_ex(c, dt, i)	(MD5Init(c), (dt ? 1 : 1))
 # define EVP_DigestUpdate(c, p, s)	MD5Update(c, (const void *)(p), \
 						  s)
 # define EVP_DigestFinal(c, d, pdl)	\
