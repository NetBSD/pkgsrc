$NetBSD: patch-libjack_unlock.c,v 1.1 2019/06/15 08:21:33 adam Exp $

Yuck.  At least let's attempt to make this somewhat sane.
When I have the time and figure out the Right Thing(tm)
to do, perhaps I'll rewrite some of the shm code.

--- libjack/unlock.c.orig	2016-02-23 15:13:53.000000000 +0000
+++ libjack/unlock.c
@@ -44,8 +44,8 @@ static char* whitelist[] = {
 static char* library_roots[] = {
 	"/lib",
 	"/usr/lib",
-	"/usr/local/lib",
-	"/usr/X11R6/lib",
+	"@PREFIX@/lib",
+	"@X11BASE@/lib",
 	"/opt/lib",             /* solaris-y */
 	"/opt/local/lib",       /* common on OS X */
 	NULL
@@ -63,7 +63,7 @@ cleanup_mlock ()
 	int whoknows;
 	int looks_like_library;
 
-	snprintf (path, sizeof(path), "/proc/%d/maps", getpid ());
+	snprintf (path, sizeof(path), "@JACKD_PROCFS_PATH@/%d/maps", getpid ());
 
 	if ((map = fopen (path, "r")) == NULL) {
 		jack_error ("can't open map file");
