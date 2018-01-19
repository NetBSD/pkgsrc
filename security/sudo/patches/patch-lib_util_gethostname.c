$NetBSD: patch-lib_util_gethostname.c,v 1.1.2.2 2018/01/19 20:22:41 spz Exp $

Avoid segfault if hostname is not set
(upstream commit)

--- lib/util/gethostname.c.orig	2017-01-14 04:30:15.000000000 +0000
+++ lib/util/gethostname.c
@@ -42,7 +42,7 @@ sudo_gethostname_v1(void)
 
     hname = malloc(host_name_max + 1);
     if (hname != NULL) {
-	if (gethostname(hname, host_name_max + 1) == 0) {
+	if (gethostname(hname, host_name_max + 1) == 0 && *hname != '\0') {
 	    /* Old gethostname() may not NUL-terminate if there is no room. */
 	    hname[host_name_max] = '\0';
 	} else {
