$NetBSD: patch-main_acl.c,v 1.1.1.1 2016/10/25 08:17:05 jnemeth Exp $

--- main/acl.c.orig	2015-10-09 21:48:48.000000000 +0000
+++ main/acl.c
@@ -127,7 +127,7 @@ static int get_local_address(struct ast_
 	char *buf = NULL;
 	int bufsz, x;
 #endif /* SOLARIS */
-#if defined(__OpenBSD__) || defined(__NetBSD__) || defined(__FreeBSD__) || defined(__linux__) || defined(__Darwin__) || defined(__GLIBC__)
+#if defined(__OpenBSD__) || defined(__NetBSD__) || defined(__FreeBSD__) || defined(__linux__) || defined(__Darwin__) || defined(__DragonFly__) || defined(__GLIBC__)
 	struct ifaddrs *ifap, *ifaphead;
 	int rtnerr;
 	const struct sockaddr_in *sin;
@@ -136,7 +136,7 @@ static int get_local_address(struct ast_
 	int best_score = -100;
 	memset(&best_addr, 0, sizeof(best_addr));
 
-#if defined(__OpenBSD__) || defined(__NetBSD__) || defined(__FreeBSD__) || defined(__linux__) || defined(__Darwin__) || defined(__GLIBC__)
+#if defined(__OpenBSD__) || defined(__NetBSD__) || defined(__FreeBSD__) || defined(__linux__) || defined(__Darwin__) || defined(__DragonFly__) || defined(__GLIBC__)
 	rtnerr = getifaddrs(&ifaphead);
 	if (rtnerr) {
 		perror(NULL);
@@ -147,7 +147,7 @@ static int get_local_address(struct ast_
 	s = socket(AF_INET, SOCK_STREAM, 0);
 
 	if (s > 0) {
-#if defined(__OpenBSD__) || defined(__NetBSD__) || defined(__FreeBSD__) || defined(__linux__) || defined(__Darwin__) || defined(__GLIBC__)
+#if defined(__OpenBSD__) || defined(__NetBSD__) || defined(__FreeBSD__) || defined(__linux__) || defined(__Darwin__) || defined(__DragonFly__) || defined(__GLIBC__)
 		for (ifap = ifaphead; ifap; ifap = ifap->ifa_next) {
 
 			if (ifap->ifa_addr && ifap->ifa_addr->sa_family == AF_INET) {
@@ -206,7 +206,7 @@ static int get_local_address(struct ast_
 
 		close(s);
 	}
-#if defined(__OpenBSD__) || defined(__NetBSD__) || defined(__FreeBSD__) || defined(__linux__) || defined(__Darwin__)
+#if defined(__OpenBSD__) || defined(__NetBSD__) || defined(__FreeBSD__) || defined(__linux__) || defined(__Darwin__) || defined(__DragonFly__)
 	freeifaddrs(ifaphead);
 #endif /* BSD_OR_LINUX */
 
