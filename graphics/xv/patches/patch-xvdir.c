$NetBSD: patch-xvdir.c,v 1.1 2023/07/30 07:55:45 tsutsui Exp $

- add webp support from forked upstream
  https://gitlab.com/DavidGriffith/xv/-/commit/5682a07e

--- xvdir.c.orig	2023-07-30 04:38:20.909134802 +0000
+++ xvdir.c
@@ -65,8 +65,11 @@ static const char *saveFormats[] = {
 #ifdef HAVE_JP2K
 					"JPEG 2000",
 					"JP2",
-#endif 
+#endif
 					"GIF",
+#ifdef HAVE_WEBP
+                                        "WEBP",
+#endif
 #ifdef HAVE_TIFF
 					"TIFF",
 #endif
@@ -1235,6 +1238,16 @@ int DoSave()
   }
 #endif
 
+
+#ifdef HAVE_WEBP
+  else if (fmt == F_WEBP) {   /* WEBP */
+    WEBPSaveParams(fullname);
+    WEBPDialog(1);                  /* open WEBP Dialog box */
+    dbut[S_BOK].lit = 0;  BTRedraw(&dbut[S_BOK]);
+    return 0;                      /* always 'succeeds' */
+  }
+#endif
+
 #ifdef HAVE_PIC2
   else if (fmt == F_PIC2) {   /* PIC2 */
     if (PIC2SaveParams(fullname, col) < 0)
@@ -1488,7 +1501,15 @@ void SetDirSaveMode(group, bnum)
       colMB.dim[F_REDUCED]   = 1;
       MBSelect(&colMB, F_BWDITHER);
     }
-
+#ifdef HAVE_WEBP
+    else if (MBWhich(&fmtMB) == F_WEBP) { /* turn off all but FULLCOLOR */
+      colMB.dim[F_FULLCOLOR] = 0;
+      colMB.dim[F_GREYSCALE] = 1;
+      colMB.dim[F_BWDITHER]  = 1;
+      colMB.dim[F_REDUCED]   = 1;
+      MBSelect(&colMB, F_FULLCOLOR);
+    }
+#endif
     else if (MBWhich(&fmtMB) == F_FITS) { /* turn off 'color' modes */
       colMB.dim[F_FULLCOLOR] = 1;
       colMB.dim[F_GREYSCALE] = 0;
@@ -1578,6 +1599,9 @@ static void changeSuffix()
 #ifdef HAVE_PNG
       (strcmp(lowsuf,"png" )==0) ||
 #endif
+#ifdef HAVE_WEBP
+      (strcmp(lowsuf,"webp")==0) ||
+#endif
       (strcmp(lowsuf,"wbmp")==0) ||
       (strcmp(lowsuf,"xpm" )==0) ||
       (strcmp(lowsuf,"tiff")==0) ||
@@ -1645,6 +1669,10 @@ static void changeSuffix()
     case F_MAKI:     strcpy(lowsuf,"mki");  break;
 #endif
 
+#ifdef HAVE_WEBP
+    case F_WEBP:     strcpy(lowsuf,"webp"); break;
+#endif
+
 #ifdef HAVE_PI
     case F_PI:       strcpy(lowsuf,"pi");   break;
 #endif
