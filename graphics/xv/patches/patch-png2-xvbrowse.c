$NetBSD: patch-png2-xvbrowse.c,v 1.1 1999/06/13 16:23:54 hubertf Exp $

This patch is based on
http://www.mit.edu/afs/athena/contrib/graphics/src/xv/patches/png/xvpng.diff
It was edited to fit into the NetBSD Packages Collection! - HF

---------------------------------------------------------------------------


--- xvbrowse.c.patched	Sun Jun 13 03:22:27 1999
+++ xvbrowse.c	Sun Jun 13 03:25:38 1999
@@ -61,6 +61,7 @@
 #include "bits/br_pic"
 #include "bits/br_pi"
 #include "bits/br_pic2"
+#include "bits/br_png"
 
 #include "bits/br_trash"
 #include "bits/fcurs"
@@ -106,7 +107,8 @@
 #define BF_PI       31
 #define BF_PIC2     32
 #define BF_PCD      33
-#define BF_MAX      34    /* # of built-in icons */
+#define BF_PNG      34
+#define BF_MAX      35    /* # of built-in icons */
 
 #define ISLOADABLE(ftyp) (ftyp!=BF_DIR  && ftyp!=BF_CHR && ftyp!=BF_BLK && \
 			  ftyp!=BF_SOCK && ftyp!=BF_FIFO) 
@@ -543,6 +545,7 @@
   bfIcons[BF_PI]  = MakePix1(br->win,br_pi_bits,br_pi_width,br_pi_height);
   bfIcons[BF_PIC2]=MakePix1(br->win,br_pic2_bits,br_pic2_width,br_pic2_height);
   bfIcons[BF_PCD] = MakePix1(br->win,br_pcd_bits,br_pcd_width,br_pcd_height);
+  bfIcons[BF_PNG]=MakePix1(br->win,br_png_bits,br_png_width,br_png_height);
 
 
   /* check that they all got built */
@@ -3045,6 +3048,7 @@
     case RFT_PI:       bf->ftype = BF_PI;       break;
     case RFT_PIC2:     bf->ftype = BF_PIC2;     break;
     case RFT_PCD:      bf->ftype = BF_PCD;      break;
+    case RFT_PNG:      bf->ftype = BF_PNG;      break;
     }
   }
 }
@@ -3612,6 +3616,7 @@
   case RFT_PI:       strcat(str,"PI file");               break;
   case RFT_PIC2:     strcat(str,"PIC2 file");             break;
   case RFT_PCD:      strcat(str,"PhotoCD file");          break;
+  case RFT_PNG:      strcat(str,"PNG file");              break;
   default:           strcat(str,"file of unknown type");  break;
   }
   
