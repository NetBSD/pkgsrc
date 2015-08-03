$NetBSD: patch-include_violite.h,v 1.2 2015/08/03 14:51:30 manu Exp $

1) SCO support

2) Port from mysql to fix SSL connexions with OpenSSL >= 1.0.1p
https://github.com/mysql/mysql-server/commit/866b988a76e8e7e217017a7883a52a12ec5024b9

From 866b988a76e8e7e217017a7883a52a12ec5024b9 Mon Sep 17 00:00:00 2001
From: Marek Szymczak <marek.szymczak@oracle.com>
Date: Thu, 9 Oct 2014 16:39:43 +0200
Subject: [PATCH] Bug#18367167 DH KEY LENGTH OF 1024 BITS TO MEET MINIMUM REQ
 OF FIPS 140-2

Perfect Forward Secrecy (PFS) requires Diffie-Hellman (DH) parameters to be set.
 Current implementation uses DH key of 512 bit.

--- include/violite.h.orig	2015-08-03 16:42:17.000000000 +0200
+++ include/violite.h	2015-08-03 16:42:06.000000000 +0200
@@ -126,9 +126,10 @@
 enum enum_ssl_init_error
 {
   SSL_INITERR_NOERROR= 0, SSL_INITERR_CERT, SSL_INITERR_KEY, 
   SSL_INITERR_NOMATCH, SSL_INITERR_BAD_PATHS, SSL_INITERR_CIPHERS, 
-  SSL_INITERR_MEMFAIL, SSL_INITERR_LASTERR
+  SSL_INITERR_MEMFAIL, SSL_INITERR_NO_USABLE_CTX, SSL_INITERR_DHFAIL,
+  SSL_INITERR_LASTERR
 };
 const char* sslGetErrString(enum enum_ssl_init_error err);
 
 struct st_VioSSLFd
@@ -211,10 +212,16 @@
   my_socket		sd;		/* my_socket - real or imaginary */
   HANDLE hPipe;
   my_bool		localhost;	/* Are we from localhost? */
   int			fcntl_mode;	/* Buffered fcntl(sd,F_GETFL) */
+#if defined(_SCO_DS)
+/* SCO OpenServer 5.0.7/3.2 has no sockaddr_storage. */
+  struct sockaddr_in	local;		/* Local internet address */
+  struct sockaddr_in	remote;		/* Remote internet address */
+#else
   struct sockaddr_storage	local;		/* Local internet address */
   struct sockaddr_storage	remote;		/* Remote internet address */
+#endif
   int addrLen;                          /* Length of remote address */
   enum enum_vio_type	type;		/* Type of connection */
   char			desc[30];	/* String description */
   char                  *read_buffer;   /* buffer for vio_read_buff */
@@ -232,9 +239,14 @@
   my_bool (*is_blocking)(Vio*);
   int     (*viokeepalive)(Vio*, my_bool);
   int     (*fastsend)(Vio*);
   my_bool (*peer_addr)(Vio*, char *, uint16*, size_t);
+/* SCO OpenServer 5.0.7/3.2 has no sockaddr_storage. */
+#if defined(_SCO_DS)
+  void    (*in_addr)(Vio*, struct sockaddr_in*);
+#else
   void    (*in_addr)(Vio*, struct sockaddr_storage*);
+#endif
   my_bool (*should_retry)(Vio*);
   my_bool (*was_interrupted)(Vio*);
   int     (*vioclose)(Vio*);
   void	  (*timeout)(Vio*, unsigned int which, unsigned int timeout);
