$NetBSD: patch-channels_chan__oss.c,v 1.1.1.1 2016/10/25 08:17:08 jnemeth Exp $

--- channels/chan_oss.c.orig	2015-10-09 21:48:48.000000000 +0000
+++ channels/chan_oss.c
@@ -53,7 +53,7 @@ ASTERISK_FILE_VERSION(__FILE__, "$Revisi
 
 #ifdef __linux
 #include <linux/soundcard.h>
-#elif defined(__FreeBSD__) || defined(__CYGWIN__) || defined(__GLIBC__) || defined(__sun)
+#elif defined(__FreeBSD__) || defined(__CYGWIN__) || defined(__GLIBC__) || defined(__sun) || defined(__DragonFly__)
 #include <sys/soundcard.h>
 #else
 #include <soundcard.h>
@@ -257,7 +257,7 @@ struct chan_oss_pvt {
 	char *name;
 	int total_blocks;			/*!< total blocks in the output device */
 	int sounddev;
-	enum { M_UNSET, M_FULL, M_READ, M_WRITE } duplex;
+	enum { M_UNSET, M_FULL, M_READ_foo, M_WRITE } duplex;
 	int autoanswer;             /*!< Boolean: whether to answer the immediately upon calling */
 	int autohangup;             /*!< Boolean: whether to hangup the call when the remote end hangs up */
 	int hookstate;              /*!< Boolean: 1 if offhook; 0 if onhook */
@@ -524,7 +524,7 @@ static int setformat(struct chan_oss_pvt
 		break;
 
 	case O_RDONLY:
-		o->duplex = M_READ;
+		o->duplex = M_READ_foo;
 		break;
 	}
 
