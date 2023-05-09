$NetBSD: patch-asyncpg_pgproto_hton.h,v 1.1 2023/05/09 08:27:10 tm Exp $

Provide illumos/solaris support to include the required endian.h

--- asyncpg/pgproto/hton.h.orig	2022-10-26 21:41:11.000000000 +0000
+++ asyncpg/pgproto/hton.h
@@ -1,6 +1,6 @@
 #include <stdint.h>
 
-#if defined(__linux__) || defined(__CYGWIN__)
+#if defined(__linux__) || defined(__CYGWIN__) || defined(__sun)
 #include <endian.h>
 #elif defined(__NetBSD__) || defined(__FreeBSD__) || defined(__OpenBSD__) \
       || defined(__DragonFly__)
