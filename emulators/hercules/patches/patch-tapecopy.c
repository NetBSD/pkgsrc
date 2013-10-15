$NetBSD: patch-tapecopy.c,v 1.3 2013/10/15 14:14:53 ryoon Exp $

--- tapecopy.c.orig	2013-06-14 21:32:42.000000000 +0000
+++ tapecopy.c
@@ -245,15 +245,21 @@ static void print_usage (void)
 static int obtain_status (char *devname, int devfd, struct mtget* mtget)
 {
 int rc;                                 /* Return code               */
+long gstat;
 
     rc = ioctl_tape (devfd, MTIOCGET, (char*)mtget);
     if (rc < 0)
     {
+#if (defined(BSD) && BSD >= 199306)
+	gstat = (mtget->mt_dsreg << 16) | mtget->mt_erreg;
+#else
+	gstat = mtget->mt_gstat;
+#endif
         if (1
             && EIO == errno
             && (0
-                || GMT_EOD( mtget->mt_gstat )
-                || GMT_EOT( mtget->mt_gstat )
+                || GMT_EOD( gstat )
+                || GMT_EOT( gstat )
             )
         )
             return +1;
@@ -263,8 +269,8 @@ int rc;                                 
         return -1;
     }
 
-    if (GMT_EOD( mtget->mt_gstat ) ||
-        GMT_EOT( mtget->mt_gstat ))
+    if (GMT_EOD( gstat ) ||
+        GMT_EOT( gstat ))
         return +1;
 
     return 0;
@@ -499,9 +505,14 @@ int64_t         file_bytes;             
 char            pathname[MAX_PATH];     /* file name in host format  */
 struct mtget    mtget;                  /* Area for MTIOCGET ioctl   */
 #if defined(EXTERNALGUI)
+#if defined(BSD) && BSD >= 199306
+struct mtget    mtpos;                  /* Area for MTIOCPOS ioctl   */
+#else
 struct mtpos    mtpos;                  /* Area for MTIOCPOS ioctl   */
+#endif
 int             is3590 = 0;             /* 1 == 3590, 0 == 3480/3490 */
 #endif /*defined(EXTERNALGUI)*/
+long		gstat;
 
     INITIALIZE_UTILITY("tapecopy");
 
@@ -639,8 +650,13 @@ int             is3590 = 0;             
         printf (_("HHCTC004I %s tape density code: 0x%lX\n"),
             (devnamein ? devnamein : devnameout), density);
 
-    if (mtget.mt_gstat != 0)
-        print_status ((devnamein ? devnamein : devnameout), mtget.mt_gstat);
+#if (defined(BSD) && BSD >= 199306)
+    gstat = (mtget.mt_dsreg << 16) | mtget.mt_erreg;
+#else
+    gstat = mtget.mt_gstat;
+#endif
+    if (gstat != 0)
+        print_status ((devnamein ? devnamein : devnameout), gstat);
 
     /* Open the disk file */
     if (filenamein)
