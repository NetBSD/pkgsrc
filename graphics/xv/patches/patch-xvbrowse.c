$NetBSD: patch-xvbrowse.c,v 1.1 2023/07/30 07:55:45 tsutsui Exp $

- add webp support from forked upstream
  https://gitlab.com/DavidGriffith/xv/-/commit/5682a07e

--- xvbrowse.c.orig	2023-07-30 04:38:20.155639398 +0000
+++ xvbrowse.c
@@ -69,6 +69,7 @@ typedef unsigned int mode_t;  /* file mo
 #include "bits/br_targa"
 #include "bits/br_tiff"
 #include "bits/br_utah"
+#include "bits/br_webp"
 #include "bits/br_xbm"
 #include "bits/br_xpm"
 #include "bits/br_xwd"
@@ -117,7 +118,8 @@ typedef unsigned int mode_t;  /* file mo
 #define BF_PCD      30
 #define BF_BZIP2    31
 #define BF_JP2      32
-#define BF_JPC      33
+#define BF_WEBP     33
+#define BF_JPC      34
 #define JP_EXT_BF   (BF_JPC)
 #define BF_MAG      (JP_EXT_BF + 1)
 #define BF_MAKI     (JP_EXT_BF + 2)
@@ -605,6 +607,7 @@ void CreateBrowse(geom, fgstr, bgstr, hi
   bfIcons[BF_PS]  =MakePix1(br->win,br_ps_bits,  br_ps_width,  br_ps_height);
   bfIcons[BF_TGA] =MakePix1(br->win,br_tga_bits, br_tga_width, br_tga_height);
   bfIcons[BF_TIFF]=MakePix1(br->win,br_tiff_bits,br_tiff_width,br_tiff_height);
+  bfIcons[BF_WEBP]=MakePix1(br->win,br_webp_bits,br_webp_width,br_webp_height);
   bfIcons[BF_XBM] =MakePix1(br->win,br_xbm_bits, br_xbm_width, br_xbm_height);
   bfIcons[BF_XPM] =MakePix1(br->win,br_xpm_bits, br_xpm_width, br_xpm_height);
   bfIcons[BF_XWD] =MakePix1(br->win,br_xwd_bits, br_xwd_width, br_xwd_height);
@@ -3351,6 +3354,7 @@ static void scanFile(br, bf, name)
     case RFT_PI:       bf->ftype = BF_PI;       break;
     case RFT_PIC2:     bf->ftype = BF_PIC2;     break;
     case RFT_MGCSFX:   bf->ftype = BF_MGCSFX;   break;
+    case RFT_WEBP:     bf->ftype = BF_WEBP;     break;
     }
   }
 }
@@ -3975,6 +3979,7 @@ ms_auto_no:
   case RFT_PI:       strcat(str,"PI file");               break;
   case RFT_PIC2:     strcat(str,"PIC2 file");             break;
   case RFT_MGCSFX:   strcat(str,"Magic Suffix file");     break;
+  case RFT_WEBP:     strcat(str,"WEBP file");             break;
   default:           strcat(str,"file of unknown type");  break;
   }
 
