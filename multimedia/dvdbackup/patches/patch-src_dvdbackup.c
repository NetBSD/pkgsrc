$NetBSD: patch-src_dvdbackup.c,v 1.1 2012/01/29 02:48:30 jakllsch Exp $

--- src/dvdbackup.c.orig	2009-06-08 22:25:29.000000000 +0000
+++ src/dvdbackup.c
@@ -1254,6 +1254,13 @@ int DVDGetTitleName(const char *device, 
 	/* Variables for filehandel and title string interaction */
 
 	int filehandle, i, last;
+	unsigned char *buf;
+
+	buf = malloc(DVD_VIDEO_LB_LEN);
+	if (buf == NULL) {
+		fprintf(stderr, _("Cannot read title from DVD device %s\n"), device);
+		return(1);
+	}
 
 	/* Open DVD device */
 
@@ -1264,7 +1271,7 @@ int DVDGetTitleName(const char *device, 
 
 	/* Seek to title of first track, which is at (track_no * 32768) + 40 */
 
-	if ( 32808 != lseek(filehandle, 32808, SEEK_SET) ) {
+	if ( 32768 != lseek(filehandle, 32768, SEEK_SET) ) {
 		close(filehandle);
 		fprintf(stderr, _("Cannot seek DVD device %s - check your DVD device\n"), device);
 		return(1);
@@ -1272,12 +1279,15 @@ int DVDGetTitleName(const char *device, 
 
 	/* Read the DVD-Video title */
 
-	if ( 32 != read(filehandle, title, 32)) {
+	if ( DVD_VIDEO_LB_LEN != read(filehandle, buf, DVD_VIDEO_LB_LEN)) {
 		close(filehandle);
 		fprintf(stderr, _("Cannot read title from DVD device %s\n"), device);
 		return(1);
 	}
 
+	memcpy(title, &buf[40], 32);
+	free(buf);
+
 	/* Terminate the title string */
 
 	title[32] = '\0';
