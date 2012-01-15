$NetBSD: patch-main_acl.c,v 1.1.1.1 2012/01/15 18:36:21 jnemeth Exp $

--- main/acl.c.orig	2011-11-08 18:01:11.000000000 +0000
+++ main/acl.c
@@ -123,7 +123,7 @@ static int get_local_address(struct ast_
 	char *buf = NULL;
 	int bufsz, x;
 #endif /* SOLARIS */
-#if defined(__OpenBSD__) || defined(__NetBSD__) || defined(__FreeBSD__) || defined(__linux__) || defined(__Darwin__) || defined(__GLIBC__)
+#if defined(__OpenBSD__) || defined(__NetBSD__) || defined(__FreeBSD__) || defined(__linux__) || defined(__Darwin__) || defined(__DragonFly__) || defined(__GLIBC__)
 	struct ifaddrs *ifap, *ifaphead;
 	int rtnerr;
 	const struct sockaddr_in *sin;
@@ -132,7 +132,7 @@ static int get_local_address(struct ast_
 	int best_score = -100;
 	memset(&best_addr, 0, sizeof(best_addr));
 
-#if defined(__OpenBSD__) || defined(__NetBSD__) || defined(__FreeBSD__) || defined(__linux__) || defined(__Darwin__) || defined(__GLIBC__)
+#if defined(__OpenBSD__) || defined(__NetBSD__) || defined(__FreeBSD__) || defined(__linux__) || defined(__Darwin__) || defined(__DragonFly__) || defined(__GLIBC__)
 	rtnerr = getifaddrs(&ifaphead);
 	if (rtnerr) {
 		perror(NULL);
@@ -143,7 +143,7 @@ static int get_local_address(struct ast_
 	s = socket(AF_INET, SOCK_STREAM, 0);
 
 	if (s > 0) {
-#if defined(__OpenBSD__) || defined(__NetBSD__) || defined(__FreeBSD__) || defined(__linux__) || defined(__Darwin__) || defined(__GLIBC__)
+#if defined(__OpenBSD__) || defined(__NetBSD__) || defined(__FreeBSD__) || defined(__linux__) || defined(__Darwin__) || defined(__DragonFly__) || defined(__GLIBC__)
 		for (ifap = ifaphead; ifap; ifap = ifap->ifa_next) {
 
 			if (ifap->ifa_addr && ifap->ifa_addr->sa_family == AF_INET) {
@@ -202,7 +202,7 @@ static int get_local_address(struct ast_
 
 		close(s);
 	}
-#if defined(__OpenBSD__) || defined(__NetBSD__) || defined(__FreeBSD__) || defined(__linux__) || defined(__Darwin__)
+#if defined(__OpenBSD__) || defined(__NetBSD__) || defined(__FreeBSD__) || defined(__linux__) || defined(__Darwin__) || defined(__DragonFly__)
 	freeifaddrs(ifaphead);
 #endif /* BSD_OR_LINUX */
 
