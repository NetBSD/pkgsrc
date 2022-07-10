$NetBSD: patch-extensions_gggl.c,v 1.4 2022/07/10 20:23:39 wiz Exp $

Patch also submitted upstream:                                                                    
       https://bugzilla.gnome.org/show_bug.cgi?id=795726                                          
                                                                                                  
Fixes crashes on alignment critical architectures.                                                

--- extensions/gggl.c.orig	2022-03-22 17:12:57.000000000 +0100
+++ extensions/gggl.c	2022-07-07 16:37:57.027502951 +0200
@@ -79,21 +79,25 @@ conv_F_16 (const Babl    *conversion,
            long           samples)
 {
   long n = samples;
+  unsigned short v;
 
   while (n--)
     {
       float f = ((*(float *) src));
       if (f < 0.0f)
         {
-          *(unsigned short *) dst = 0;
+          v = 0;
+	  memcpy(dst, &v, sizeof(v));
         }
       else if (f > 1.0f)
         {
-          *(unsigned short *) dst = 65535;
+          v = 65535;
+	  memcpy(dst, &v, sizeof(v));
         }
       else
         {
-          *(unsigned short *) dst = lrint (f * 65535.0f);
+	  v = lrint (f * 65535.0f);
+	  memcpy(dst, &v, sizeof(v));
         }
       dst += 2;
       src += 4;
@@ -126,7 +130,8 @@ conv_16_F (const Babl    *conversion,
 
   while (n--)
     {
-      (*(float *) dst) = *(unsigned short *) src / 65535.0;
+      float v = *src / 65535.0;
+      memcpy(dst, &v, sizeof(v));
       dst             += 4;
       src             += 2;
     }
@@ -170,7 +175,11 @@ conv_F_D (const Babl    *conversion,
 
   while (n--)
     {
-      *(double *) dst = ((*(float *) src));
+      float sv;
+      double dv;
+      memcpy(&sv, src, sizeof(sv));
+      dv = (float)sv;
+      memcpy(dst, &dv, sizeof(dv));
       dst            += 8;
       src            += 4;
     }
@@ -186,7 +195,11 @@ conv_D_F (const Babl    *conversion,
 
   while (n--)
     {
-      *(float *) dst = ((*(double *) src));
+      float dv;
+      double sv;
+      memcpy(&sv, src, sizeof(sv));
+      dv = sv;
+      memcpy(dst, &dv, sizeof(dv));
       dst           += 4;
       src           += 8;
     }
@@ -214,7 +227,9 @@ conv_16_8 (const Babl    *conversion,
 
   while (n--)
     {
-      (*(unsigned char *) dst) = div_257 (*(unsigned short *) src);
+      unsigned short sv;
+      memcpy(&sv, src, sizeof(sv));
+      *dst = div_257 (sv);
       dst += 1;
       src += 2;
     }
@@ -229,7 +244,8 @@ conv_8_16 (const Babl    *conversion,
   long n = samples;
   while (n--)
     {
-      (*(unsigned short *) dst) = *src << 8 | *src;
+      unsigned short dv = (*src << 8) | *src;
+      memcpy(dst, &dv, sizeof(dv));
       dst += 2;
       src += 1;
     }
@@ -454,12 +470,14 @@ conv_gaF_gAF (const Babl    *conversion,
 
   while (n--)
     {
-      float alpha = (*(float *) (src + 4));
-
-      *(float *) dst = ((*(float *) src) * alpha);
+      float alpha, sv;
+      memcpy(&alpha, src + 4, sizeof(alpha));
+      memcpy(&sv, src, sizeof(sv));
+      sv *= alpha;
+      memcpy(dst, &sv, sizeof(sv));
       dst           += 4;
       src           += 4;
-      *(float *) dst = alpha;
+      memcpy(dst, &alpha, sizeof(alpha));
       dst           += 4;
       src           += 4;
     }
@@ -475,15 +493,19 @@ conv_gAF_gaF (const Babl    *conversion,
 
   while (n--)
     {
-      float alpha = (*(float *) (src + 4));
+      float alpha, sv, dv;
+      memcpy(&alpha, src+4, sizeof(alpha));
 
       if (alpha == 0.0f)
-        *(float *) dst = 0.0f;
-      else
-        *(float *) dst = ((*(float *) src) / alpha);
+        dv = 0.0f;
+      else {
+        memcpy(&sv, src, sizeof(sv));
+	dv = sv / alpha;
+      }
+      memcpy(dst, &dv, sizeof(dv));
       dst           += 4;
       src           += 4;
-      *(float *) dst = alpha;
+      memcpy(dst, &alpha, sizeof(alpha));
       dst           += 4;
       src           += 4;
     }
@@ -501,16 +523,9 @@ conv_rgbaF_rgbF (const Babl    *conversi
 
   while (n--)
     {
-      *(uint32_t *) dst = (*(uint32_t *) src);
-      dst           += 4;
-      src           += 4;
-      *(uint32_t *) dst = (*(uint32_t *) src);
-      dst           += 4;
-      src           += 4;
-      *(uint32_t *) dst = (*(uint32_t *) src);
-      dst           += 4;
-      src           += 4;
-      src           += 4;
+      memcpy(dst, src, 4*3);
+      dst           += 4*3;
+      src           += 4*4;
     }
 }
 
@@ -521,15 +536,12 @@ conv_rgbF_rgbaF (const Babl    *conversi
                  long           samples)
 {
   long n = samples;
-  float *fsrc = (void*) src;
-  float *fdst = (void*) dst;
+  float one = 1.0f;
 
   while (n--)
     {
-      *fdst++ = *fsrc++;
-      *fdst++ = *fsrc++; 
-      *fdst++ = *fsrc++;
-      *fdst++ = 1.0f;
+      memcpy(dst, src, sizeof(float)*3);
+      memcpy(dst, &one, sizeof(one));
     }
 }
 
@@ -546,7 +558,7 @@ conv_gaF_gF (const Babl    *conversion,
 
   while (n--)
     {
-      *(int *) dst = (*(int *) src);
+      memcpy(dst, src, 4);
       dst         += 4;
       src         += 4;
       src         += 4;
@@ -560,13 +572,14 @@ conv_gF_gaF (const Babl    *conversion,
              long           samples)
 {
   long n = samples;
+  float one = 1.0f;
 
   while (n--)
     {
-      *(float *) dst = (*(float *) src);
+      memcpy(dst, src, sizeof(float));
       dst           += 4;
       src           += 4;
-      *(float *) dst = 1.0;
+      memcpy(dst, &one, sizeof(one));
       dst           += 4;
     }
 }
@@ -591,7 +604,7 @@ conv_gF_rgbF (const Babl    *conversion,
 
       for (c = 0; c < 3; c++)
         {
-          (*(float *) dst) = (*(float *) src);
+          memcpy(dst, src, 4);
           dst             += 4;
         }
       src += 4;
@@ -649,11 +662,11 @@ conv_gaF_rgbaF (const Babl    *conversio
 
       for (c = 0; c < 3; c++)
         {
-          (*(int *) dst) = (*(int *) src);
+          memcpy(dst, src, 4);
           dst           += 4;
         }
       src           += 4;
-      (*(int *) dst) = (*(int *) src);
+      memcpy(dst, src, 4);
       dst           += 4;
       src           += 4;
     }
@@ -696,6 +709,7 @@ conv_rgbaF_rgb16 (const Babl    *convers
                   long           samples)
 {
   long n = samples;
+  unsigned short v;
 
   while (n--)
     {
@@ -703,12 +717,16 @@ conv_rgbaF_rgb16 (const Babl    *convers
 
       for (c = 0; c < 3; c++)
         {
-          if ((*(float *) src) >= 1.0f)
-            *(unsigned short *) dst = 65535;
-          else if ((*(float *) src) <=0)
-            *(unsigned short *) dst = 0;
-          else
-            *(unsigned short *) dst = lrint ((*(float *) src) * 65535.0f);
+          if ((*(float *) src) >= 1.0f) {
+	    v = 65535;
+	    memcpy(dst, &v, sizeof(v));
+          } else if ((*(float *) src) <=0) {
+	    v = 0;
+	    memcpy(dst, &v, sizeof(v));
+          } else {
+            v = lrint ((*(float *) src) * 65535.0f);
+	    memcpy(dst, &v, sizeof(v));
+	  }
           dst                    += 2;
           src                    += 4;
         }
@@ -726,10 +744,14 @@ conv_rgbA16_rgbaF (const Babl    *conver
 
   while (n--)
     {
-      float alpha = (((unsigned short *) src)[3]) / 65535.0;
+      unsigned short v;
+      float alpha, f;
       int   c;
       float recip_alpha;
 
+      memcpy(&v, src+3*sizeof(unsigned short), sizeof(v));
+      alpha = v / 65535.0;
+
       if (alpha == 0.0f)
         recip_alpha = 10000.0;
       else
@@ -737,11 +759,13 @@ conv_rgbA16_rgbaF (const Babl    *conver
 
       for (c = 0; c < 3; c++)
         {
-          (*(float *) dst) = (*(unsigned short *) src / 65535.0f) * recip_alpha;
+	  memcpy(&v, src, sizeof(v));
+          f = (v / 65535.0f) * recip_alpha;
+	  memcpy(dst, &f, sizeof(f));
           dst             += 4;
           src             += 2;
         }
-      *(float *) dst = alpha;
+      memcpy(dst, &alpha, sizeof(alpha));
       dst           += 4;
       src           += 2;
     }
@@ -754,16 +778,13 @@ conv_gF_rgbaF (const Babl    *conversion
                long           samples)
 {
   long n = samples;
+  float one = 1.0f;
 
   while (n--)
     {
-      *(int *) dst   = (*(int *) src);
-      dst           += 4;
-      *(int *) dst   = (*(int *) src);
-      dst           += 4;
-      *(int *) dst   = (*(int *) src);
-      dst           += 4;
-      *(float *) dst = 1.0;
+      memcpy(dst, src, 3*4);
+      dst           += 3*4;
+      memcpy(dst, &one, sizeof(one));
       dst           += 4;
       src           += 4;
     }
@@ -816,15 +837,21 @@ conv_gF_rgbaF (const Babl    *conversion
                   int samples)
    {
     long n=samples;
+    float one = 1.0f;
+
     while (n--) {
         int c;
 
         for (c = 0; c < 3; c++) {
- *(float *) dst = (*(unsigned short *) src) / 65535.0;
+	    unsigned short v;
+	    float d;
+	    memcpy(&v, src, sizeof(v));
+	    d = v / 65535.0;
+	    memcpy(dst, &d, sizeof(d));
             src += 2;
             dst += 4;
         }
- *(float *) dst = 1.0;
+        memcpy(dst, &one, sizeof(one));
         src += 2;
         dst += 4;
     }
@@ -836,14 +863,12 @@ conv_gF_rgbaF (const Babl    *conversion
                int samples)
    {
     long n=samples;
+    float one = 1.0f;
+
     while (n--) {
-        (*(float *) dst) = (*(float *) src);
-        dst += 4;
-        (*(float *) dst) = (*(float *) src);
-        dst += 4;
-        (*(float *) dst) = (*(float *) src);
-        dst += 4;
-        (*(float *) dst) = 1.0;
+        memcpy(dst, src, 4*3);
+        dst += 4*3;
+	memcpy(dst, &one, 4);
         dst += 4;
         src += 4;
 
@@ -862,11 +887,12 @@ conv_rgba8_rgbA8 (const Babl    *convers
     {
       if (src[3] == 255)
         {
-          *(unsigned int *) dst = *(unsigned int *) src;
+          memcpy(dst, src, 4);
         }
       else if (src[3] == 0)
         {
-          *(unsigned int *) dst = 0;
+	  unsigned int zero = 0;
+	  memcpy(dst, &zero, 4);
         }
       else
         {
@@ -893,12 +919,13 @@ conv_rgbA8_rgba8 (const Babl    *convers
     {
       if (src[3] == 255)
         {
-          *(unsigned int *) dst = *(unsigned int *) src;
+          memcpy(dst, src, 4);
           dst                  += 4;
         }
       else if (src[3] == 0)
         {
-          *(unsigned int *) dst = 0;
+	  unsigned int zero = 0;
+	  memcpy(dst, &zero, 4);
           dst                  += 4;
         }
       else
@@ -925,7 +952,10 @@ conv_rgb8_rgba8 (const Babl    *conversi
   long n = samples-1;
   while (n--)
     {
-      *(unsigned int *) dst = (*(unsigned int *) src) | (255UL << 24);
+      unsigned int sv, dv;
+      memcpy(&sv, src, sizeof(sv));
+      dv = sv | (255UL << 24);
+      memcpy(dst, &dv, sizeof(dv));
       src   += 3;
       dst   += 4;
     }
