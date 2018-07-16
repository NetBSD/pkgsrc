$NetBSD: patch-channels_chan__oss.c,v 1.1 2018/07/16 21:53:05 joerg Exp $

--- channels/chan_oss.c.orig	2018-05-01 20:12:26.000000000 +0000
+++ channels/chan_oss.c
@@ -51,7 +51,7 @@
 
 #ifdef __linux
 #include <linux/soundcard.h>
-#elif defined(__FreeBSD__) || defined(__CYGWIN__) || defined(__GLIBC__) || defined(__sun)
+#elif defined(__FreeBSD__) || defined(__CYGWIN__) || defined(__GLIBC__) || defined(__sun) || defined(__DragonFly__)
 #include <sys/soundcard.h>
 #else
 #include <soundcard.h>
@@ -255,7 +255,7 @@ struct chan_oss_pvt {
 	char *name;
 	int total_blocks;			/*!< total blocks in the output device */
 	int sounddev;
-	enum { M_UNSET, M_FULL, M_READ, M_WRITE } duplex;
+	enum { M_UNSET, M_FULL, M_READ_foo, M_WRITE } duplex;
 	int autoanswer;             /*!< Boolean: whether to answer the immediately upon calling */
 	int autohangup;             /*!< Boolean: whether to hangup the call when the remote end hangs up */
 	int hookstate;              /*!< Boolean: 1 if offhook; 0 if onhook */
@@ -522,7 +522,7 @@ static int setformat(struct chan_oss_pvt
 		break;
 
 	case O_RDONLY:
-		o->duplex = M_READ;
+		o->duplex = M_READ_foo;
 		break;
 	}
 
@@ -1310,7 +1310,7 @@ static void store_mixer(struct chan_oss_
 	int i;
 
 	for (i = 0; i < strlen(s); i++) {
-		if (!isalnum(s[i]) && strchr(" \t-/", s[i]) == NULL) {
+		if (!isalnum((unsigned char)s[i]) && strchr(" \t-/", s[i]) == NULL) {
 			ast_log(LOG_WARNING, "Suspect char %c in mixer cmd, ignoring:\n\t%s\n", s[i], s);
 			return;
 		}
