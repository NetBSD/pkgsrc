$NetBSD: patch-src_afsd_afsd.c,v 1.1 2012/08/30 17:37:55 jakllsch Exp $

--- src/afsd/afsd.c.orig	2010-12-17 15:58:42.000000000 +0000
+++ src/afsd/afsd.c
@@ -2382,8 +2382,12 @@ mainproc(struct cmd_syndesc *as, void *a
 	if ((mount("AFS", cacheMountDir, MOUNT_AFS, 0, NULL)) < 0) {
 #else
 /* This is the standard mount used by the suns and rts */
+#if defined(__NetBSD__) && __NetBSD_Prereq__(4,99,24)
+	if (1) {
+#else
 	if ((mount(MOUNT_AFS, cacheMountDir, mountFlags, (caddr_t) 0)) < 0) {
 #endif
+#endif
 	    printf("%s: Can't mount AFS on %s(%d)\n", rn, cacheMountDir,
 		   errno);
 	    exit(1);
