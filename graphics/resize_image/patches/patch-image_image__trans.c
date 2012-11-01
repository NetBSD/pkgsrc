$NetBSD: patch-image_image__trans.c,v 1.1 2012/11/01 19:52:03 joerg Exp $

Remove nested functions.

--- image/image_trans.c.orig	2012-10-30 19:37:02.000000000 +0000
+++ image/image_trans.c
@@ -200,6 +200,7 @@ void image_resize_dct(image *pdest, imag
   uint8 val[8][8];
   float dct_res[8][8];    /* coefficient 3d qui correspondent a nos pixels */
   float dc_coeff;
+  uint8 res;
   
   /* initialise le tableau des fonctions de bases */
   double f1,f2,tmp;
@@ -215,70 +216,65 @@ void image_resize_dct(image *pdest, imag
   uint32 nb_pix;
   float  percent_done,percent_tmp;
 
-  void init_dct(void)
-  {
-    f1 = 2.0*atan(1.0)/8.0;
-    for(y=0;y<8;y++){         /* de la fonction 0 a la 7              */
-      f2=(double)y*f1;
-      for(x=0;x<8;x++){       /* du point 0 au point 7 de la fonction */
-        tmp=cos((double)(2*x+1)*f2);
-        if(y==0) dct_coeff[y][x]=(float)(1.0/sqrt(2.0));
-        else     dct_coeff[y][x]=(float)tmp;
-      }
-    }
-    dc_coeff = 1.0/sqrt(2.0);
-  }
-
-  void calcul_dct(void)
-  {    
-    for(i2 = 0; i2 < 8; i2++)
-    {
-      for(i1 = 0; i1 < 8; i1++)
-      {
-        dct_res[i2][i1] = 0.0;
-
-        for(y = 0; y < 8; y++)
-          for(x = 0; x < 8; x++)
-            dct_res[i2][i1] += dct_coeff[i1][x] * dct_coeff[i2][y]
-              * (float)val[y][x];
-        dct_res[i2][i1] /= 16.0;
-      }
-    }
-  } /* fin de calcul_dct() */
-
-  uint8 calcul_pix(float px, float py)
-  { uint8 res;
-  
-    float temp;
-    float dct_coeff_hor[8],dct_coeff_ver[8];
-
-    for(y=0;y<8;y++)
-    {
-      f2=(double)y*f1;
-      if(y==0) {
-        dct_coeff_hor[y]=dc_coeff;
-      } else {
-        tmp=cos((double)(2.0*(4.0-px)+1.0)*f2);
-        dct_coeff_hor[y]=(float)tmp;
-      }
-      if(y==0) {
-        dct_coeff_ver[y]=dc_coeff;
-      } else {
-        tmp=cos((double)(2.0*(4.0-py)+1.0)*f2);
-        dct_coeff_ver[y]=(float)tmp;
-      }
-    }
-    
-    temp = 0.0;
-    for(y=0;y<8;y++)
-      for(x=0;x<8;x++)
-        temp += dct_coeff_hor[x] * dct_coeff_ver[y] * dct_res[y][x];
-
-    if(temp > 255.0) res = 255;
-    else if(temp < 0.0) res = 0;
-    else res = (uint8)temp;
-    return(res);
-  }
+#define init_dct() do { \
+    f1 = 2.0*atan(1.0)/8.0; \
+    for(y=0;y<8;y++){         /* de la fonction 0 a la 7              */ \
+      f2=(double)y*f1; \
+      for(x=0;x<8;x++){       /* du point 0 au point 7 de la fonction */ \
+        tmp=cos((double)(2*x+1)*f2); \
+        if(y==0) dct_coeff[y][x]=(float)(1.0/sqrt(2.0)); \
+        else     dct_coeff[y][x]=(float)tmp; \
+      } \
+    } \
+    dc_coeff = 1.0/sqrt(2.0); \
+  } while (0)
+
+#define calcul_dct() do { \
+    for(i2 = 0; i2 < 8; i2++) \
+    { \
+      for(i1 = 0; i1 < 8; i1++) \
+      { \
+        dct_res[i2][i1] = 0.0; \
+ \
+        for(y = 0; y < 8; y++) \
+          for(x = 0; x < 8; x++) \
+            dct_res[i2][i1] += dct_coeff[i1][x] * dct_coeff[i2][y] \
+              * (float)val[y][x]; \
+        dct_res[i2][i1] /= 16.0; \
+      } \
+    } \
+  } /* fin de calcul_dct() */ while (0)
+
+#define calcul_pix(px, py) do { \
+    float temp; \
+    float dct_coeff_hor[8],dct_coeff_ver[8]; \
+ \
+    for(y=0;y<8;y++) \
+    { \
+      f2=(double)y*f1; \
+      if(y==0) { \
+        dct_coeff_hor[y]=dc_coeff; \
+      } else { \
+        tmp=cos((double)(2.0*(4.0-px)+1.0)*f2); \
+        dct_coeff_hor[y]=(float)tmp; \
+      } \
+      if(y==0) { \
+        dct_coeff_ver[y]=dc_coeff; \
+      } else { \
+        tmp=cos((double)(2.0*(4.0-py)+1.0)*f2); \
+        dct_coeff_ver[y]=(float)tmp; \
+      } \
+    } \
+  \
+    temp = 0.0; \
+    for(y=0;y<8;y++) \
+      for(x=0;x<8;x++) \
+        temp += dct_coeff_hor[x] * dct_coeff_ver[y] * dct_res[y][x]; \
+ \
+    if(temp > 255.0) res = 255; \
+    else if(temp < 0.0) res = 0; \
+    else res = (uint8)temp; \
+  } while(0)
   
   /* corp de la procedure */
   init_dct();
@@ -314,19 +310,22 @@ void image_resize_dct(image *pdest, imag
         for(x=0;x<8;x++)
           val[y][x] = COL_RED(get_pix(psrc,((int32)rx)-x+4,((int32)ry)-y+4));
       calcul_dct();
-      SET_COL_RED(vcol,calcul_pix(x_dist, y_dist));
+      calcul_pix(x_dist, y_dist);
+      SET_COL_RED(vcol, res);
       /* pour le vert */
       for(y=0;y<8;y++)
         for(x=0;x<8;x++)
           val[y][x] = COL_GREEN(get_pix(psrc,((int32)rx)-x+4,((int32)ry)-y+4));
       calcul_dct();
-      SET_COL_GREEN(vcol,calcul_pix(x_dist, y_dist));
+      calcul_pix(x_dist, y_dist);
+      SET_COL_GREEN(vcol,res);
       /* pour le bleu */
       for(y=0;y<8;y++)
         for(x=0;x<8;x++)
           val[y][x] = COL_BLUE(get_pix(psrc,((int32)rx)-x+4,((int32)ry)-y+4));
       calcul_dct();
-      SET_COL_BLUE(vcol,calcul_pix(x_dist, y_dist));
+      calcul_pix(x_dist, y_dist);
+      SET_COL_BLUE(vcol,res);
       /* on place le pixel calcule */
       put_pix_alpha_replace(pdest, vx, vy, vcol);
       
@@ -370,25 +369,26 @@ void image_resize_catmull_rom(image *pde
   image *img_width;
 
   /* calcul la valeur du point a la position t */
-  void calcul_dot(float t)
-  { float t2,t3;
-    float xt,yt,zt,wt;
-
-    /* calcul t au carre */
-    t2 = t*t;
-    /* calcul t au cube */
-    t3 = t2*t;
-
-    /* on multiplie le vecteur (t3,t2,t,1) par la matrice mat */
-    xt = t3*mat[0] + t2*mat[4] + t*mat[ 8] + mat[12];
-    yt = t3*mat[1] + t2*mat[5] + t*mat[ 9] + mat[13];
-    zt = t3*mat[2] + t2*mat[6] + t*mat[10] + mat[14];
-    wt = t3*mat[3] + t2*mat[7] + t*mat[11] + mat[15];
-    /* on multiplie le resultat par la matrice des contraintes */
-    x = xt*dot[0] + yt*dot[3] + zt*dot[6] + wt*dot[9];
-    y = xt*dot[1] + yt*dot[4] + zt*dot[7] + wt*dot[10];
-    z = xt*dot[2] + yt*dot[5] + zt*dot[8] + wt*dot[11];
-  }
+#define calcul_dot(t_) do { \
+    float t = (t_); \
+    float t2,t3; \
+    float xt,yt,zt,wt; \
+ \
+    /* calcul t au carre */ \
+    t2 = t*t; \
+    /* calcul t au cube */ \
+    t3 = t2*t; \
+ \
+    /* on multiplie le vecteur (t3,t2,t,1) par la matrice mat */ \
+    xt = t3*mat[0] + t2*mat[4] + t*mat[ 8] + mat[12]; \
+    yt = t3*mat[1] + t2*mat[5] + t*mat[ 9] + mat[13]; \
+    zt = t3*mat[2] + t2*mat[6] + t*mat[10] + mat[14]; \
+    wt = t3*mat[3] + t2*mat[7] + t*mat[11] + mat[15]; \
+    /* on multiplie le resultat par la matrice des contraintes */ \
+    x = xt*dot[0] + yt*dot[3] + zt*dot[6] + wt*dot[9]; \
+    y = xt*dot[1] + yt*dot[4] + zt*dot[7] + wt*dot[10]; \
+    z = xt*dot[2] + yt*dot[5] + zt*dot[8] + wt*dot[11]; \
+  } while (0)
 
   width_scale  = (float)psrc->width  / (float)width;
   height_scale = (float)psrc->height / (float)height;
@@ -572,40 +572,43 @@ void image_resize_tv2(image *pdest, imag
 { pix vcol,vcol1,vcol2,vcol3,vcol4;
   int32 vx,vy;
 
-  void redim_col(float dim)
-  {
-    vcol = COL(
-      (uint8)MIN(255,MAX(0,(((float)COL_RED(vcol))*dim))),
-      (uint8)MIN(255,MAX(0,(((float)COL_GREEN(vcol))*dim))),
-      (uint8)MIN(255,MAX(0,(((float)COL_BLUE(vcol))*dim))));
-  }
-
-  void redim_lum(float dim_y,float dim_cr,float dim_cb)
-  { float cr,cb,y;
-    float r,g,b;
-  
-    y = 0.299*(float)COL_RED(vcol)+
-        0.587*(float)COL_GREEN(vcol)+
-        0.114*(float)COL_BLUE(vcol);
-    cr = (float)COL_RED(vcol)  - y;
-    cb = (float)COL_BLUE(vcol) - y;
-
-/*    y = (1.0+cos(M_PI+((y/255.0)*M_PI)))*128.0;*/
-
-    y *= dim_y;
-    cr *= dim_cr;
-    cb *= dim_cb;
-
-    r = cr + y; 
-    b = cb + y; 
-    g = y*1.7 - r*0.509 - b*0.194;
-    
-    r = MIN(255.0,MAX(0,r));
-    g = MIN(255.0,MAX(0,g));
-    b = MIN(255.0,MAX(0,b));
-    
-    vcol = COL((uint8)r,(uint8)g,(uint8)b);
-  }
+#define redim_col(dim_) do { \
+    float dim = (dim_); \
+    vcol = COL( \
+      (uint8)MIN(255,MAX(0,(((float)COL_RED(vcol))*dim))), \
+      (uint8)MIN(255,MAX(0,(((float)COL_GREEN(vcol))*dim))), \
+      (uint8)MIN(255,MAX(0,(((float)COL_BLUE(vcol))*dim)))); \
+  } while(0)
+
+#define redim_lum(dim_y_, dim_cr_, dim_cb_) do { \
+    float dim_y = (dim_y_); \
+    float dim_cr = (dim_cr_); \
+    float dim_cb = (dim_cb_); \
+    float cr,cb,y; \
+    float r,g,b; \
+ \
+    y = 0.299*(float)COL_RED(vcol)+ \
+        0.587*(float)COL_GREEN(vcol)+ \
+        0.114*(float)COL_BLUE(vcol); \
+    cr = (float)COL_RED(vcol)  - y; \
+    cb = (float)COL_BLUE(vcol) - y; \
+ \
+/*    y = (1.0+cos(M_PI+((y/255.0)*M_PI)))*128.0;*/ \
+ \
+    y *= dim_y; \
+    cr *= dim_cr; \
+    cb *= dim_cb; \
+ \
+    r = cr + y; \
+    b = cb + y; \
+    g = y*1.7 - r*0.509 - b*0.194; \
+ \
+    r = MIN(255.0,MAX(0,r)); \
+    g = MIN(255.0,MAX(0,g)); \
+    b = MIN(255.0,MAX(0,b)); \
+ \
+    vcol = COL((uint8)r,(uint8)g,(uint8)b); \
+  } while (0)
 
   /* si les préconditions ne sont pas remplies, on quitte */
   if((pdest == NULL) || (psrc == NULL) ||
@@ -653,135 +656,136 @@ void image_resize_tv2(image *pdest, imag
 /* Redimentionne l'image psrc et place le resultat          */
 /* dans pdest. pdest doit être 2 fois plus grande que psrc. */
 void image_resize_most(image *pdest, image *psrc)
-{ pix vcol1,vcol2,vcol3,vcol4,vcolm;
+{ pix vcol1,vcol2,vcol3,vcol4,vcolm, most_upper, most_left;
   int32 vx,vy;
 
-  pix find_most_middle(void)
-  { float y[4];
-    int   pos[4];
-    int   min_pos, i1, i2;
-    float swap_float;
-    int   swap_int;
-
-    y[0] = (0.299*(float)COL_RED(vcol1)+
-           0.587*(float)COL_GREEN(vcol1)+
-           0.114*(float)COL_BLUE(vcol1))*1.2;
-    y[1] = 0.299*(float)COL_RED(vcol2)+
-           0.587*(float)COL_GREEN(vcol2)+
-           0.114*(float)COL_BLUE(vcol2);
-    y[2] = 0.299*(float)COL_RED(vcol3)+
-           0.587*(float)COL_GREEN(vcol3)+
-           0.114*(float)COL_BLUE(vcol3);
-    y[3] = 0.299*(float)COL_RED(vcol4)+
-           0.587*(float)COL_GREEN(vcol4)+
-           0.114*(float)COL_BLUE(vcol4);
-    pos[0] = 0; pos[1] = 1; pos[2] = 2; pos[3] = 3;
-
-    for(i1=0;i1<4-1;i1++)
-    {
-      min_pos = i1;
-      for(i2=i1;i2<4;i2++)
-      {
-        if(y[i2] < y[min_pos]) min_pos = i2;
-      }
-      swap_float = y[i1];
-      swap_int   = pos[i1];
-      y[i1]      = y[min_pos];
-      pos[i1]    = pos[min_pos];
-      y[min_pos] = swap_float;
-      pos[min_pos] = swap_int;
-    }
-    switch(pos[1])
-    {
-      case 0 : return(vcol1);
-      case 1 : return(vcol2);
-      case 2 : return(vcol3);
-      case 3 : return(vcol4);
-    }
-    return(BLACK);
-  }
-
-  pix find_most_upper(void)
-  { float y[3];
-    int   pos[3];
-    int   min_pos, i1, i2;
-    float swap_float;
-    int   swap_int;
-
-    y[0] = 0.299*(float)COL_RED(vcol1)+
-           0.587*(float)COL_GREEN(vcol1)+
-           0.114*(float)COL_BLUE(vcol1);
-    y[1] = 0.299*(float)COL_RED(vcol2)+
-           0.587*(float)COL_GREEN(vcol2)+
-           0.114*(float)COL_BLUE(vcol2);
-    y[2] = (0.299*(float)COL_RED(vcolm)+
-           0.587*(float)COL_GREEN(vcolm)+
-           0.114*(float)COL_BLUE(vcolm))*1.2;
-    pos[0] = 0; pos[1] = 1; pos[2] = 2;
-
-    for(i1=0;i1<3-1;i1++)
-    {
-      min_pos = i1;
-      for(i2=i1;i2<3;i2++)
-      {
-        if(y[i2] < y[min_pos]) min_pos = i2;
-      }
-      swap_float = y[i1];
-      swap_int   = pos[i1];
-      y[i1]      = y[min_pos];
-      pos[i1]    = pos[min_pos];
-      y[min_pos] = swap_float;
-      pos[min_pos] = swap_int;
-    }
-    switch(pos[1])
-    {
-      case 0 : return(vcol1);
-      case 1 : return(vcol2);
-      case 2 : return(vcolm);
-    }
-    return(vcolm);
-  }
-
-  pix find_most_left(void)
-  { float y[3];
-    int   pos[3];
-    int   min_pos, i1, i2;
-    float swap_float;
-    int   swap_int;
-
-    y[0] = 0.299*(float)COL_RED(vcol1)+
-           0.587*(float)COL_GREEN(vcol1)+
-           0.114*(float)COL_BLUE(vcol1);
-    y[1] = 0.299*(float)COL_RED(vcol3)+
-           0.587*(float)COL_GREEN(vcol3)+
-           0.114*(float)COL_BLUE(vcol3);
-    y[2] = (0.299*(float)COL_RED(vcolm)+
-           0.587*(float)COL_GREEN(vcolm)+
-           0.114*(float)COL_BLUE(vcolm))*1.2;
-    pos[0] = 0; pos[1] = 1; pos[2] = 2;
-
-    for(i1=0;i1<3-1;i1++)
-    {
-      min_pos = i1;
-      for(i2=i1;i2<3;i2++)
-      {
-        if(y[i2] < y[min_pos]) min_pos = i2;
-      }
-      swap_float = y[i1];
-      swap_int   = pos[i1];
-      y[i1]      = y[min_pos];
-      pos[i1]    = pos[min_pos];
-      y[min_pos] = swap_float;
-      pos[min_pos] = swap_int;
-    }
-    switch(pos[1])
-    {
-      case 0 : return(vcol1);
-      case 1 : return(vcol3);
-      case 2 : return(vcolm);
-    }
-    return(vcolm);
-  }
+#define find_most_middle() do { \
+    float y[4]; \
+    int   pos[4]; \
+    int   min_pos, i1, i2; \
+    float swap_float; \
+    int   swap_int; \
+ \
+    y[0] = (0.299*(float)COL_RED(vcol1)+ \
+           0.587*(float)COL_GREEN(vcol1)+ \
+           0.114*(float)COL_BLUE(vcol1))*1.2; \
+    y[1] = 0.299*(float)COL_RED(vcol2)+ \
+           0.587*(float)COL_GREEN(vcol2)+ \
+           0.114*(float)COL_BLUE(vcol2); \
+    y[2] = 0.299*(float)COL_RED(vcol3)+ \
+           0.587*(float)COL_GREEN(vcol3)+ \
+           0.114*(float)COL_BLUE(vcol3); \
+    y[3] = 0.299*(float)COL_RED(vcol4)+ \
+           0.587*(float)COL_GREEN(vcol4)+ \
+           0.114*(float)COL_BLUE(vcol4); \
+    pos[0] = 0; pos[1] = 1; pos[2] = 2; pos[3] = 3; \
+ \
+    for(i1=0;i1<4-1;i1++) \
+    { \
+      min_pos = i1; \
+      for(i2=i1;i2<4;i2++) \
+      { \
+        if(y[i2] < y[min_pos]) min_pos = i2; \
+      } \
+      swap_float = y[i1]; \
+      swap_int   = pos[i1]; \
+      y[i1]      = y[min_pos]; \
+      pos[i1]    = pos[min_pos]; \
+      y[min_pos] = swap_float; \
+      pos[min_pos] = swap_int; \
+    } \
+    switch(pos[1]) \
+    { \
+      case 0 : vcom = vcol1; break; \
+      case 1 : vcom = vcol2; break; \
+      case 2 : vcom = vcol3; break; \
+      case 3 : vcom = vcol4; break; \
+      default: \
+        vcom = BLACK; break; \
+    } \
+  } while(0)
+
+#define find_most_upper(void) do { \
+    float y[3]; \
+    int   pos[3]; \
+    int   min_pos, i1, i2; \
+    float swap_float; \
+    int   swap_int; \
+ \
+    y[0] = 0.299*(float)COL_RED(vcol1)+ \
+           0.587*(float)COL_GREEN(vcol1)+ \
+           0.114*(float)COL_BLUE(vcol1); \
+    y[1] = 0.299*(float)COL_RED(vcol2)+ \
+           0.587*(float)COL_GREEN(vcol2)+ \
+           0.114*(float)COL_BLUE(vcol2); \
+    y[2] = (0.299*(float)COL_RED(vcolm)+ \
+           0.587*(float)COL_GREEN(vcolm)+ \
+           0.114*(float)COL_BLUE(vcolm))*1.2; \
+    pos[0] = 0; pos[1] = 1; pos[2] = 2; \
+ \
+    for(i1=0;i1<3-1;i1++) \
+    { \
+      min_pos = i1; \
+      for(i2=i1;i2<3;i2++) \
+      { \
+        if(y[i2] < y[min_pos]) min_pos = i2; \
+      } \
+      swap_float = y[i1]; \
+      swap_int   = pos[i1]; \
+      y[i1]      = y[min_pos]; \
+      pos[i1]    = pos[min_pos]; \
+      y[min_pos] = swap_float; \
+      pos[min_pos] = swap_int; \
+    } \
+    switch(pos[1]) \
+    { \
+      case 0 : most_upper = vcol1; break; \
+      case 1 : most_upper = vcol2; break; \
+      case 2 : most_upper = vcolm; break; \
+      default: most_upper = vcolm; break; \
+    } \
+  } while (0)
+
+#define find_most_left() do { \
+    float y[3]; \
+    int   pos[3]; \
+    int   min_pos, i1, i2; \
+    float swap_float; \
+    int   swap_int; \
+ \
+    y[0] = 0.299*(float)COL_RED(vcol1)+ \
+           0.587*(float)COL_GREEN(vcol1)+ \
+           0.114*(float)COL_BLUE(vcol1); \
+    y[1] = 0.299*(float)COL_RED(vcol3)+ \
+           0.587*(float)COL_GREEN(vcol3)+ \
+           0.114*(float)COL_BLUE(vcol3); \
+    y[2] = (0.299*(float)COL_RED(vcolm)+ \
+           0.587*(float)COL_GREEN(vcolm)+ \
+           0.114*(float)COL_BLUE(vcolm))*1.2; \
+    pos[0] = 0; pos[1] = 1; pos[2] = 2; \
+ \
+    for(i1=0;i1<3-1;i1++) \
+    { \
+      min_pos = i1;\
+      for(i2=i1;i2<3;i2++) \
+      { \
+        if(y[i2] < y[min_pos]) min_pos = i2; \
+      } \
+      swap_float = y[i1]; \
+      swap_int   = pos[i1]; \
+      y[i1]      = y[min_pos]; \
+      pos[i1]    = pos[min_pos]; \
+      y[min_pos] = swap_float; \
+      pos[min_pos] = swap_int; \
+    } \
+    switch(pos[1]) \
+    { \
+      case 0 : most_left = vcol1; break; \
+      case 1 : most_left = vcol2; break; \
+      case 2 : most_left = vcolm; break; \
+      default : most_left = vcolm; break; \
+    } \
+  } while(0)
 
   /* si les préconditions ne sont pas remplies, on quitte */
   if((pdest == NULL) || (psrc == NULL) ||
@@ -798,10 +802,11 @@ void image_resize_most(image *pdest, ima
       vcol4 = get_pix(psrc, vx+1, vy+1);
       
       put_pix_alpha_replace(pdest, (vx<<1), (vy<<1), vcol1);
-      vcolm = find_most_middle();
       put_pix_alpha_replace(pdest, (vx<<1)+1, (vy<<1)+1, vcolm);
-      put_pix_alpha_replace(pdest, (vx<<1)+1, (vy<<1), find_most_upper());
-      put_pix_alpha_replace(pdest, (vx<<1), (vy<<1)+1, find_most_left());
+      find_most_upper();
+      put_pix_alpha_replace(pdest, (vx<<1)+1, (vy<<1), most_upper);
+      find_most_left();
+      put_pix_alpha_replace(pdest, (vx<<1), (vy<<1)+1, most_left);
     }
   }
 }
