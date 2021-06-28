$NetBSD: patch-fortune_fortune.c,v 1.2 2021/06/28 11:20:55 tnn Exp $

Make fortune compatible with BSD strfile datfiles.

--- fortune/fortune.c.orig	1997-08-28 19:43:52.000000000 +0000
+++ fortune/fortune.c
@@ -142,6 +142,20 @@ static char rcsid[] = "$NetBSD: fortune.
 #define	NDEBUG	1
 #endif
 
+#ifdef __APPLE__
+#include <libkern/OSByteOrder.h>
+#define BE32TOH(x) x = OSSwapBigToHostInt32(x)
+#define BE64TOH(x) x = OSSwapBigToHostInt64(x)
+#elif defined __sun
+#define BE32TOH(x) x = BE_IN32(&(x))
+#define BE64TOH(x) x = BE_IN64(&(x))
+#elif defined __linux__
+#define _BSD_SOURCE
+#include <endian.h>
+#define BE32TOH(x) x = be32toh(x)
+#define BE64TOH(x) x = be64toh(x)
+#endif
+
 typedef struct fd
 {
     int percent;
@@ -925,10 +939,10 @@ void get_tbl(FILEDESC * fp)
 	    exit(1);
 	}
 	/* fp->tbl.str_version = ntohl(fp->tbl.str_version); */
-	fp->tbl.str_numstr = ntohl(fp->tbl.str_numstr);
-	fp->tbl.str_longlen = ntohl(fp->tbl.str_longlen);
-	fp->tbl.str_shortlen = ntohl(fp->tbl.str_shortlen);
-	fp->tbl.str_flags = ntohl(fp->tbl.str_flags);
+	BE32TOH(fp->tbl.str_numstr);
+	BE32TOH(fp->tbl.str_longlen);
+	BE32TOH(fp->tbl.str_shortlen);
+	BE32TOH(fp->tbl.str_flags);
 	close(fd);
     }
     else
@@ -1098,8 +1112,8 @@ void get_fort(void)
     lseek(fp->datfd,
 	  (off_t) (sizeof fp->tbl + fp->pos * sizeof Seekpts[0]), 0);
     read(fp->datfd, Seekpts, sizeof Seekpts);
-    Seekpts[0] = ntohl(Seekpts[0]);
-    Seekpts[1] = ntohl(Seekpts[1]);
+    BE64TOH(Seekpts[0]);
+    BE64TOH(Seekpts[1]);
 }
 
 /*
