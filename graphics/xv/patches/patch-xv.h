$NetBSD: patch-xv.h,v 1.5 2026/03/18 16:19:54 nia Exp $

- don't declare errno and sys_errlist
- use strerror
- use getcwd, not getwd
- add webp support from forked upstream
  https://gitlab.com/DavidGriffith/xv/-/commit/5682a07e
- pull XRandR support from forked upstream
  https://gitlab.com/DavidGriffith/xv/-/commit/a84406cb

--- xv.h.orig	2026-03-18 16:17:56.151309998 +0000
+++ xv.h
@@ -139,9 +139,7 @@
 #endif
 
 
-#if defined(__FreeBSD__)
-#  include <sys/param.h>
-#endif
+#include <sys/param.h>
 
 
 /* include files */
@@ -160,7 +158,7 @@
 #ifndef VMS
 #  include <errno.h>
 #  ifndef __NetBSD__
-#    if !(defined __GLIBC__ && __GLIBC__ >= 2)
+#    if !(defined(BSD) && (BSD >= 199103)) && !(defined __GLIBC__ && __GLIBC__ >= 2)
        extern int   errno;         /* SHOULD be in errno.h, but often isn't */
        extern char *sys_errlist[]; /* this too... */
 #    endif
@@ -172,7 +170,7 @@
 #ifdef VMS
 #  define ERRSTR(x) strerror(x, vaxc$errno)
 #else
-#  if defined(__BEOS__) || defined(__linux__) /* or all modern/glibc systems? */
+#  if defined(__BEOS__) || defined(__linux__) || defined(__sun) /* or all modern/glibc systems? */
 #    define ERRSTR(x) strerror(x)
 #  else
 #    define ERRSTR(x) sys_errlist[x]
@@ -196,6 +194,9 @@
 #  include <perror.h>
 #endif
 
+#if defined(__sun) || defined(__linux__)
+#  include <alloca.h>
+#endif
 
 /* GRR 20070512:  Very few modern systems even have a malloc.h anymore;
  *                stdlib.h is, well, the standard.  (Former explicitly listed
@@ -208,7 +209,9 @@
 #  if defined(hp300) || defined(hp800) || defined(NeXT)
 #    include <sys/malloc.h>    /* it's in "sys" on HPs and NeXT */
 #  else
-#    include <malloc.h>
+#    ifndef __DARWIN__
+#      include <malloc.h>
+#    endif
 #  endif
 #endif
 
@@ -222,6 +225,11 @@
 #include <X11/Xatom.h>
 #include <X11/Xmd.h>
 
+#ifdef HAVE_XRR
+#include <X11/Xproto.h>
+#include <X11/extensions/Xrandr.h>
+#endif
+
 #ifdef TV_L10N
 #  include <X11/Xlocale.h>
 #endif
@@ -392,7 +400,7 @@
 #  endif
 #endif
 
-#if (defined(SYSV) || defined(SVR4) || defined(linux)) && !defined(USE_GETCWD)
+#if (defined(SYSV) || defined(SVR4) || defined(linux) || defined(__NetBSD__) || defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__DragonFly__)) && !defined(USE_GETCWD)
 #  define USE_GETCWD
 #endif
 
@@ -411,6 +419,9 @@
 /* END OF CONFIGURATION INFO */
 /*****************************/
 
+#ifdef DOWEBP
+#  define HAVE_WEBP
+#endif
 
 #ifdef DOJPEG
 #  define HAVE_JPEG
@@ -568,6 +579,12 @@
 #  define F_TIFINC  0
 #endif
 
+#ifdef HAVE_WEBP
+#  define F_WEBPINC  1
+#else
+#  define F_WEBPINC  0
+#endif
+
 #ifdef HAVE_PNG
 #  define F_PNGINC  1
 #else
@@ -621,7 +638,8 @@
 #define F_JPC       ( 0 + F_PNGINC + F_JPGINC)
 #define F_JP2       ( 0 + F_PNGINC + F_JPGINC + F_JP2INC)
 #define F_GIF       ( 0 + F_PNGINC + F_JPGINC + F_JP2INC + F_JP2INC)  /* always avail; index varies */
-#define F_TIFF      ( 0 + F_PNGINC + F_JPGINC + F_JP2INC + F_JP2INC + F_TIFINC)
+#define F_WEBP      ( 0 + F_PNGINC + F_JPGINC + F_JP2INC + F_JP2INC + F_WEBPINC)
+#define F_TIFF      ( 0 + F_PNGINC + F_JPGINC + F_JP2INC + F_JP2INC + F_WEBPINC + F_TIFINC)
 #define F_PS        ( 1 + F_TIFF)
 #define F_PBMRAW    ( 2 + F_TIFF)
 #define F_PBMASCII  ( 3 + F_TIFF)
@@ -691,6 +709,7 @@
 #define RFT_PI       (JP_EXT_RFT + 4)
 #define RFT_PIC2     (JP_EXT_RFT + 5)
 #define RFT_MGCSFX   (JP_EXT_RFT + 6)
+#define RFT_WEBP     (JP_EXT_RFT + 7)
 
 /* definitions for page up/down, arrow up/down list control */
 #define LS_PAGEUP   0
@@ -1404,6 +1423,11 @@ WHERE Window        pngW;
 WHERE int           pngUp;        /* is pngW mapped, or what? */
 #endif
 
+#ifdef HAVE_WEBP
+/* stuff used for 'webp' box */
+WHERE Window        webpW;
+WHERE int           webpUp;       /* is webpW mapped, or what? */
+#endif
 
 #ifdef ENABLE_FIXPIX_SMOOTH
 WHERE int           do_fixpix_smooth;  /* GRR 19980607: runtime FS dithering */
@@ -2094,6 +2118,14 @@ int LoadSunRas             PARM((char *,
 int WriteSunRas            PARM((FILE *, byte *, int, int, int, byte *,
 				 byte *, byte*, int, int, int));
 
+/**************************** XVWEBP.C ***************************/
+int LoadWEBP               PARM((char *, PICINFO *));
+void CreateWEBPW           PARM((void));
+void WEBPDialog            PARM((int));
+int  WEBPCheckEvent        PARM((XEvent *));
+void WEBPSaveParams        PARM((char *));
+void VersionInfoWEBP       PARM((void));
+
 /**************************** XVTARGA.C ***************************/
 int LoadTarga              PARM((char *, PICINFO *));
 int WriteTarga             PARM((FILE *, byte *, int, int, int, byte *,
