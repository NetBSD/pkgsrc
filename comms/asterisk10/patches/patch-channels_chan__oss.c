$NetBSD: patch-channels_chan__oss.c,v 1.2 2012/03/25 02:17:47 jnemeth Exp $

--- channels/chan_oss.c.orig	2011-09-09 16:27:01.000000000 +0000
+++ channels/chan_oss.c
@@ -48,7 +48,7 @@ ASTERISK_FILE_VERSION(__FILE__, "$Revisi
 
 #ifdef __linux
 #include <linux/soundcard.h>
-#elif defined(__FreeBSD__) || defined(__CYGWIN__) || defined(__GLIBC__)
+#elif defined(__FreeBSD__) || defined(__CYGWIN__) || defined(__DragonFly__) || defined(__GLIBC__)
 #include <sys/soundcard.h>
 #else
 #include <soundcard.h>
@@ -250,7 +250,7 @@ struct chan_oss_pvt {
 	char *name;
 	int total_blocks;			/*!< total blocks in the output device */
 	int sounddev;
-	enum { M_UNSET, M_FULL, M_READ, M_WRITE } duplex;
+	enum { M_UNSET, M_FULL, M_READ_foo, M_WRITE } duplex;
 	int autoanswer;             /*!< Boolean: whether to answer the immediately upon calling */
 	int autohangup;             /*!< Boolean: whether to hangup the call when the remote end hangs up */
 	int hookstate;              /*!< Boolean: 1 if offhook; 0 if onhook */
@@ -517,7 +517,7 @@ static int setformat(struct chan_oss_pvt
 		break;
 
 	case O_RDONLY:
-		o->duplex = M_READ;
+		o->duplex = M_READ_foo;
 		break;
 	}
 
