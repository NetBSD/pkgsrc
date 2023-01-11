$NetBSD: patch-plugins_check_radius.c,v 1.2 2023/01/11 09:27:28 sekiya Exp $

Do not assume that we are compiling under Linux.

Support radius config.

--- plugins/check_radius.c.orig	2023-01-11 18:07:22.189005504 +0900
+++ plugins/check_radius.c	2023-01-11 18:07:11.857369955 +0900
@@ -38,13 +38,13 @@
 
 #include <ifaddrs.h>
 
-#ifdef __FreeBSD__
-#include <net/if_dl.h>
-#else
+#if defined(__linux__)
 #include <linux/if_packet.h>
 #define AF_LINK AF_PACKET
 #define LLADDR(l) ((l)->sll_addr)
 #define sockaddr_dl sockaddr_ll
+#else
+#include <net/if_dl.h>
 #endif
 
 #if defined(HAVE_LIBFREERADIUS_CLIENT)
@@ -99,7 +99,7 @@
 char *nasipaddress = NULL;
 char *castid = NULL;
 char *expect = NULL;
-char *config_file = NULL;
+char *config_file = "@SYSCONFDIR@/radiusclient-ng/radiusclient.conf";
 unsigned short port = PW_AUTH_UDP_PORT;
 int retries = 1;
 int verbose = FALSE;
