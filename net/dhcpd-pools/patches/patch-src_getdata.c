$NetBSD: patch-src_getdata.c,v 1.2 2012/11/05 14:26:44 he Exp $

Don't include features.h; move string.h to dhcpd-pools.h.
Check return value of posix_fadvise(), not just whether errno != 0.

--- src/getdata.c.orig	2011-07-10 22:30:00.000000000 +0000
+++ src/getdata.c
@@ -43,19 +43,12 @@ extern char *malloc();
 #define EXIT_SUCCESS    0	/* Successful exit status.  */
 #endif				/* STDC_HEADERS */
 
-#ifdef  HAVE_STRING_H
-#include <string.h>
-#else
-#include <strings.h>
-#endif
-
 #include <arpa/inet.h>
 #include <assert.h>
 #include <ctype.h>
 #include <err.h>
 #include <errno.h>
 #include <fcntl.h>
-#include <features.h>
 #include <netinet/in.h>
 #include <stddef.h>
 #include <stdint.h>
@@ -89,15 +82,13 @@ int parse_leases(void)
 		err(EXIT_FAILURE, "parse_leases: %s", config.dhcpdlease_file);
 	}
 #ifdef POSIX_FADV_WILLNEED
-	posix_fadvise(fileno(dhcpd_leases), 0, 0, POSIX_FADV_WILLNEED);
-	if (errno) {
+	if (posix_fadvise(fileno(dhcpd_leases), 0, 0, POSIX_FADV_WILLNEED) != 0) {
 		err(EXIT_FAILURE, "parse_leases: fadvise %s",
 		    config.dhcpdlease_file);
 	}
 #endif				/* POSIX_FADV_WILLNEED */
 #ifdef POSIX_FADV_SEQUENTIAL
-	posix_fadvise(fileno(dhcpd_leases), 0, 0, POSIX_FADV_SEQUENTIAL);
-	if (errno) {
+	if (posix_fadvise(fileno(dhcpd_leases), 0, 0, POSIX_FADV_SEQUENTIAL) != 0) {
 		err(EXIT_FAILURE, "parse_leases: fadvise %s",
 		    config.dhcpdlease_file);
 	}
@@ -269,14 +260,12 @@ void parse_config(int is_include, char *
 		err(EXIT_FAILURE, "parse_config: %s", config_file);
 	}
 #ifdef POSIX_FADV_WILLNEED
-	posix_fadvise(fileno(dhcpd_config), 0, 0, POSIX_FADV_WILLNEED);
-	if (errno) {
+	if (posix_fadvise(fileno(dhcpd_config), 0, 0, POSIX_FADV_WILLNEED) != 0) {
 		err(EXIT_FAILURE, "parse_config: fadvise %s", config_file);
 	}
 #endif				/* POSIX_FADV_WILLNEED */
 #ifdef POSIX_FADV_SEQUENTIAL
-	posix_fadvise(fileno(dhcpd_config), 0, 0, POSIX_FADV_SEQUENTIAL);
-	if (errno) {
+	if (posix_fadvise(fileno(dhcpd_config), 0, 0, POSIX_FADV_SEQUENTIAL) != 0) {
 		err(EXIT_FAILURE, "parse_config: fadvise %s", config_file);
 	}
 #endif				/* POSIX_FADV_SEQUENTIAL */
