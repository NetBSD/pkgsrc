$NetBSD: patch-extensions_gggl.c,v 1.2 2018/11/22 12:59:07 ryoon Exp $

Patch also submitted upstream:
	https://bugzilla.gnome.org/show_bug.cgi?id=795726

Fixes crashes on alignment critical architectures.

--- extensions/gggl.c.orig	2018-10-22 16:57:44.000000000 +0000
+++ extensions/gggl.c
@@ -56,12 +56,15 @@ conv_F_8 (const Babl *conversion,unsigne
 
   while (n--)
     {
-      float f    = ((*(float *) src));
-      int   uval = lrint (f * 255.0);
+      float f;
+      int   uval;
+
+      memcpy(&f, src, sizeof(f));
+      uval = lrint (f * 255.0);
 
       if (uval < 0) uval = 0;
       if (uval > 255) uval = 255;
-      *(unsigned char *) dst = uval;
+      *dst = uval;
 
       dst += 1;
       src += 4;
@@ -72,21 +75,26 @@ static void
 conv_F_16 (const Babl *conversion,unsigned char *src, unsigned char *dst, long samples)
 {
   long n = samples;
+  unsigned short v;
 
   while (n--)
     {
-      float f = ((*(float *) src));
+      float f;
+      memcpy(&f, src, sizeof(f));
       if (f < 0.0)
         {
-          *(unsigned short *) dst = 0;
+	  v = 0;
+	  memcpy(dst, &v, sizeof(v));
         }
       else if (f > 1.0)
         {
-          *(unsigned short *) dst = 65535;
+          v = 65535;
+	  memcpy(dst, &v, sizeof(v));
         }
       else
         {
-          *(unsigned short *) dst = lrint (f * 65535.0);
+          v = lrint (f * 65535.0);
+	  memcpy(dst, &v, sizeof(v));
         }
       dst += 2;
       src += 4;
@@ -100,7 +108,9 @@ conv_8_F (const Babl *conversion,unsigne
 
   while (n--)
     {
-      (*(float *) dst) = ((*(unsigned char *) src) / 255.0);
+      float v;
+      v = *src / 255.0;
+      memcpy(dst, &v, sizeof(v));
       dst             += 4;
       src             += 1;
     }
@@ -113,7 +123,8 @@ conv_16_F (const Babl *conversion,unsign
 
   while (n--)
     {
-      (*(float *) dst) = *(unsigned short *) src / 65535.0;
+      float v = *src / 65535.0;
+      memcpy(dst, &v, sizeof(v));
       dst             += 4;
       src             += 2;
     }
@@ -130,13 +141,18 @@ conv_rgbaF_rgb8 (const Babl *conversion,
 
       for (c = 0; c < 3; c++)
         {
-          int val = rint ((*(float *) src) * 255.0);
+	  float v;
+	  int val;
+
+	  memcpy(&v, src, sizeof(v));
+          val = rint (v * 255.0);
+
           if (val < 0)
-            *(unsigned char *) dst = 0;
+            *dst = 0;
           else if (val > 255)
-            *(unsigned char *) dst = 255;
+            *dst = 255;
           else
-            *(unsigned char *) dst = val;
+            *dst = val;
           dst += 1;
           src += 4;
         }
@@ -151,7 +167,11 @@ conv_F_D (const Babl *conversion,unsigne
 
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
@@ -164,7 +184,11 @@ conv_D_F (const Babl *conversion,unsigne
 
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
@@ -189,7 +213,9 @@ conv_16_8 (const Babl *conversion,unsign
 
   while (n--)
     {
-      (*(unsigned char *) dst) = div_257 (*(unsigned short *) src);
+      unsigned short sv;
+      memcpy(&sv, src, sizeof(sv));
+      *dst = div_257 (sv);
       dst += 1;
       src += 2;
     }
@@ -201,7 +227,8 @@ conv_8_16 (const Babl *conversion,unsign
   long n = samples;
   while (n--)
     {
-      (*(unsigned short *) dst) = *src << 8 | *src;
+      unsigned short dv = (*src << 8) | *src;
+      memcpy(dst, &dv, sizeof(dv));
       dst += 2;
       src += 1;
     }
@@ -363,12 +390,14 @@ conv_gaF_gAF (const Babl *conversion,uns
 
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
@@ -381,15 +410,19 @@ conv_gAF_gaF (const Babl *conversion,uns
 
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
@@ -404,16 +437,9 @@ conv_rgbaF_rgbF (const Babl *conversion,
 
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
 
@@ -421,15 +447,12 @@ static void
 conv_rgbF_rgbaF (const Babl *conversion,unsigned char *src, unsigned char *dst, long samples)
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
 
@@ -443,7 +466,7 @@ conv_gaF_gF (const Babl *conversion,unsi
 
   while (n--)
     {
-      *(int *) dst = (*(int *) src);
+      memcpy(dst, src, 4);
       dst         += 4;
       src         += 4;
       src         += 4;
@@ -454,13 +477,14 @@ static void
 conv_gF_gaF (const Babl *conversion,unsigned char *src, unsigned char *dst, long samples)
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
@@ -482,7 +506,7 @@ conv_gF_rgbF (const Babl *conversion,uns
 
       for (c = 0; c < 3; c++)
         {
-          (*(float *) dst) = (*(float *) src);
+          memcpy(dst, src, 4);
           dst             += 4;
         }
       src += 4;
@@ -531,11 +555,11 @@ conv_gaF_rgbaF (const Babl *conversion,u
 
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
@@ -553,16 +577,20 @@ conv_rgbaF_rgbA8 (const Babl *conversion
 
   while (n--)
     {
-      float alpha = (*(float *) (src + (4 * 3)));
+      float alpha;
       int   c;
 
+      memcpy(&alpha, src + 4*3, sizeof(alpha));
+
       for (c = 0; c < 3; c++)
         {
-          *(unsigned char *) dst = lrint (((*(float *) src) * alpha) * 255.0);
+	  float sv;
+	  memcpy(&sv, src, sizeof(sv));
+          *dst = lrint ((sv * alpha) * 255.0);
           dst                   += 1;
           src                   += 4;
         }
-      *(unsigned char *) dst = lrint (alpha * 255.0);
+      *dst = lrint (alpha * 255.0);
       dst++;
       src += 4;
     }
@@ -579,12 +607,17 @@ conv_rgbaF_rgb16 (const Babl *conversion
 
       for (c = 0; c < 3; c++)
         {
-          if ((*(float *) src) >= 1.0)
-            *(unsigned short *) dst = 65535;
-          else if ((*(float *) src) <=0)
-            *(unsigned short *) dst = 0;
+	  float sv;
+	  unsigned short dv;
+
+	  memcpy(&sv, src, sizeof(sv));
+          if (sv >= 1.0)
+            dv = 65535;
+          else if (sv <=0)
+            dv = 0;
           else
-            *(unsigned short *) dst = lrint ((*(float *) src) * 65535.0);
+            dv = lrint (sv * 65535.0);
+	  memcpy(dst, &dv, 2);
           dst                    += 2;
           src                    += 4;
         }
@@ -599,10 +632,14 @@ conv_rgbA16_rgbaF (const Babl *conversio
 
   while (n--)
     {
-      float alpha = (((unsigned short *) src)[3]) / 65535.0;
+      unsigned short v;
+      float alpha;
       int   c;
       float recip_alpha;
 
+      memcpy(&v, src+3*sizeof(unsigned short), sizeof(v));
+      alpha = v / 65535.0;
+
       if (alpha == 0.0f)
         recip_alpha = 10000.0;
       else
@@ -610,11 +647,15 @@ conv_rgbA16_rgbaF (const Babl *conversio
 
       for (c = 0; c < 3; c++)
         {
-          (*(float *) dst) = (*(unsigned short *) src / 65535.0) * recip_alpha;
+	  float d;
+
+	  memcpy(&v, src, sizeof(v));
+	  d = (v / 65535.0) * recip_alpha;
+	  memcpy(dst, &d, sizeof(d));
           dst             += 4;
           src             += 2;
         }
-      *(float *) dst = alpha;
+      memcpy(dst, &alpha, sizeof(alpha));
       dst           += 4;
       src           += 2;
     }
@@ -624,16 +665,13 @@ static void
 conv_gF_rgbaF (const Babl *conversion,unsigned char *src, unsigned char *dst, long samples)
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
@@ -648,15 +686,18 @@ conv_gF_rgbaF (const Babl *conversion,un
                  int samples)
    {
     long n=samples;
+    float one = 1.0f;
+
     while (n--) {
         int c;
 
         for (c = 0; c < 3; c++) {
-            (*(float *) dst) = *(unsigned char *) src / 255.0;
+	    float dv = *src / 255.0;
+	    memcpy(dst, &dv, sizeof(dv));
             dst += 4;
             src += 1;
         }
-        (*(float *) dst) = 1.0;
+	memcpy(dst, &one, sizeof(one));
         dst += 4;
     }
    }
@@ -667,15 +708,18 @@ conv_gF_rgbaF (const Babl *conversion,un
                int samples)
    {
     long n=samples;
+    float one = 1.0f;
+
     while (n--) {
         int c;
 
         for (c = 0; c < 3; c++) {
-            (*(float *) dst) = *(unsigned char *) src / 255.0;
+	    float v = *src / 255.0;
+	    memcpy(dst, &v, sizeof(v));
             dst += 4;
         }
         src += 1;
-        (*(float *) dst) = 1.0;
+	memcpy(dst, &one, sizeof(one));
         dst += 4;
     }
    }
@@ -686,15 +730,21 @@ conv_gF_rgbaF (const Babl *conversion,un
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
@@ -706,14 +756,12 @@ conv_gF_rgbaF (const Babl *conversion,un
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
 
@@ -729,11 +777,12 @@ conv_rgba8_rgbA8 (const Babl *conversion
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
@@ -757,12 +806,13 @@ conv_rgbA8_rgba8 (const Babl *conversion
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
@@ -786,7 +836,10 @@ conv_rgb8_rgba8 (const Babl *conversion,
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
