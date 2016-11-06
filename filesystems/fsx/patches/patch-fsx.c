$NetBSD: patch-fsx.c,v 1.1 2016/11/06 16:12:08 wiz Exp $

Portability fixes for NetBSD.

--- fsx.c.orig	2016-11-06 16:10:25.886667703 +0000
+++ fsx.c
@@ -53,7 +53,9 @@
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <time.h>
+#ifdef __APPLE__
 #include <sys/paths.h>
+#endif
 #include <sys/param.h>
 #ifdef _UWIN
 # include <limits.h>
@@ -76,6 +78,9 @@
 #ifdef XILOG
 # include <XILog/XILog.h>
 #endif
+#ifndef _PATH_FORKSPECIFIER
+#define _PATH_FORKSPECIFIER "/..namedfork/"
+#endif
 
 /*
  *	A log entry is an operation and a bunch of arguments.
@@ -754,19 +759,27 @@ doread(unsigned offset, unsigned size)
 			failure(140);
 		}
 				
+#ifdef F_NOCACHE
 		if (cache_off && (fcntl(fd, F_NOCACHE, 1) != 0)) { // turn data caching off
 			logdump();
 			prterr("doread: fcntl(F_NOCACHE, 1)");
 			failure(201);
 		}
+#endif
 		iret = read(fd, temp_buf, size);
+#ifdef F_NOCACHE
 		if (cache_off && (fcntl(fd, F_NOCACHE, 0) != 0)) {
 			logdump();
 			prterr("doread: fcntl(F_NOCACHE, 0)");
 			failure(201);
 		}
+#endif
 	} else {
+#ifdef __APPLE__
 		iret = fgetxattr(fd, eaname, temp_buf, size, 0, 0);
+#else
+		iret = fgetxattr(fd, eaname, temp_buf, size);
+#endif
 	}
 
 	if (iret != size) {
@@ -947,11 +960,13 @@ dowrite(unsigned offset, unsigned size)
 					prterr("dowrite: lseek");
 					failure(150);
 				}
+#ifdef F_NOCACHE
 				if (cache_off && (fcntl(fd, F_NOCACHE, 1) != 0)) { // turn data caching off
 					logdump();
 					prterr("dowrite: fcntl(F_NOCACHE, 1)");
 					failure(201);
 				}
+#endif
 				iret = write(fd, good_buf + file_size, offset - file_size);
 				if (iret != offset - file_size) {
 					logdump();
@@ -964,11 +979,13 @@ dowrite(unsigned offset, unsigned size)
 					}
 					failure(151);
 				}
+#ifdef F_NOCACHE
 				if (cache_off && (fcntl(fd, F_NOCACHE, 0) != 0)) {
 					logdump();
 					prterr("dowrite: fcntl(F_NOCACHE, 0)");
 					failure(201);
 				}
+#endif
 			}
 		}
 		file_size = offset + size;
@@ -994,11 +1011,13 @@ dowrite(unsigned offset, unsigned size)
 			prterr("dowrite: lseek");
 			failure(150);
 		}
+#ifdef F_NOCACHE
 		if (cache_off && (fcntl(fd, F_NOCACHE, 1) != 0)) { // turn data caching off
 			logdump();
 			prterr("dowrite: fcntl(F_NOCACHE, 1)");
 			failure(201);
 		}
+#endif
 		iret = write(fd, good_buf + offset, size);
 		if (iret != size) {
 			logdump();
@@ -1011,21 +1030,31 @@ dowrite(unsigned offset, unsigned size)
 			}
 			failure(151);
 		}
+#ifdef F_NOCACHE
 		if (cache_off && (fcntl(fd, F_NOCACHE, 0) != 0)) {
 			logdump();
 			prterr("dowrite: fcntl(F_NOCACHE, 0)");
 			failure(201);
 		}
+#endif
 	} else {
 		if (random() % 2000 == 0) {
+#ifdef __APPLE__
 			iret = fremovexattr(fd, eaname, 0);
+#else
+			iret = fremovexattr(fd, eaname);
+#endif
 			if (iret != 0) {
 				logdump();
 				prterr("ea_dowrite: removexattr");
 				failure(151);
 			}
 		}
+#ifdef __APPLE__
 		iret = fsetxattr(fd, eaname, good_buf, size, 0, 0);
+#else
+		iret = fsetxattr(fd, eaname, good_buf, size, 0);
+#endif
 		ea_lastwrite = size;
 		if (iret != 0) {
 			logdump();
@@ -1101,7 +1130,7 @@ domapwrite(unsigned offset, unsigned siz
 		failure(202);
 	}
 	memcpy(p + pg_offset, good_buf + offset, size);
-	if (msync(p, map_size, 0) != 0) {
+	if (msync(p, map_size, MS_SYNC) != 0) {
 		logdump();
 		prterr("domapwrite: msync");
 		failure(203);
