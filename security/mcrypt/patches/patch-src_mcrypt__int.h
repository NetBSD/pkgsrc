$NetBSD: patch-src_mcrypt__int.h,v 1.1 2018/05/30 14:58:03 ginsbach Exp $

* Fix ARM build [XXX needed?]

From: Red Hat, SUSE

--- src/mcrypt_int.h.orig	2003-09-08 17:25:50.000000000 +0000
+++ src/mcrypt_int.h
@@ -15,3 +15,8 @@ void rol_buf(void * buffer, int buffersi
 void mcrypt_version();
 void mcrypt_license();
 void usage(void);
+
+int print_list(void);
+int print_hashlist(void);
+int print_keylist(void);
+
