$NetBSD: patch-src_client.c,v 1.1 2012/12/15 21:40:33 markd Exp $

Fix for 64bit time_t

--- src/client.c.orig	2012-09-26 15:26:32.000000000 +0000
+++ src/client.c
@@ -417,9 +417,9 @@ sendfile(char *rname, opt_t opts, struct
 		debugmsg(DM_MISC, "Turning off compression");
 	}
 
-	(void) sendcmd(C_RECVREG, "%lo %04o %ld %ld %ld %s %s %s", 
+	(void) sendcmd(C_RECVREG, "%lo %04o %ld %jd %jd %s %s %s", 
 		       (long)opts, stb->st_mode & 07777, (long) stb->st_size, 
-		       stb->st_mtime, stb->st_atime,
+		       (intmax_t)stb->st_mtime, (intmax_t)stb->st_atime,
 		       user, group, ername);
 	if (response() < 0) {
 		(void) close(f);
@@ -716,9 +716,9 @@ sendlink(char *rname, opt_t opts, struct
 	 * Gather and send basic link info
 	 */
 	ENCODE(ername, rname);
-	(void) sendcmd(C_RECVSYMLINK, "%lo %04o %ld %ld %ld %s %s %s", 
+	(void) sendcmd(C_RECVSYMLINK, "%lo %04o %ld %jd %jd %s %s %s", 
 		       (long)opts, stb->st_mode & 07777, (long) stb->st_size, 
-		       stb->st_mtime, stb->st_atime,
+		       (intmax_t)stb->st_mtime, (intmax_t)stb->st_atime,
 		       user, group, ername);
 	if (response() < 0)
 		return -1;
