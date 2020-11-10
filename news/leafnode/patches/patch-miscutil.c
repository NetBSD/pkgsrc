$NetBSD: patch-miscutil.c,v 1.1 2020/11/10 12:03:59 micha Exp $

Leafnode no longer trashes the stack if it, while scanning the message.id
directory, finds a directory with an all-numeric name that is 1000 or higher.
https://gitlab.com/leafnode-2/leafnode-1/-/commit/33e7e308d60d774b7f67c1a59851ce3718ed0355

--- miscutil.c.orig	2013-06-10 18:16:31.000000000 +0000
+++ miscutil.c
@@ -63,13 +63,16 @@ static const mode_t default_umask = 0002
 struct xoverinfo *xoverinfo;
 unsigned long xfirst, xlast;
 
+/* kludge around C89 const not being a compile-time constant */
+enum { hashsize = 1000 };
+
 static int
 createmsgiddir(void) {
     mastr *dir = mastr_new(1024);
     mastr *mid = mastr_new(1024);
     DIR *d;
     int rc = 0;
-    int havedir[1000] = {0};
+    int havedir[hashsize] = {0};
 
     mastr_vcat(dir, spooldir, "/message.id", NULL);
     d = opendir(mastr_str(dir));
@@ -84,7 +87,7 @@ createmsgiddir(void) {
 	    t = de->d_name;
 	    if (isdigit((unsigned char)*t)) {
 		u = strtoul(t, &e, 10);
-		if (e > t)
+		if (e > t && u < hashsize)
 		    havedir[u] = 1;
 	    }
 	}
@@ -96,7 +99,7 @@ createmsgiddir(void) {
 	closedir(d);
 
 	/* create missing */
-	for(u = 0; u < 1000; u++) {
+	for(u = 0; u < hashsize; u++) {
 	    char b[4];
 
 	    snprintf(b, sizeof(b), "%03lu", u);
