$NetBSD: patch-src_bin_jp2_convertbmp.c,v 1.1 2020/01/07 20:19:46 sevan Exp $

CVE-2019-12973
https://github.com/uclouvain/openjpeg/pull/1185
https://nvd.nist.gov/vuln/detail/CVE-2019-12973

--- src/bin/jp2/convertbmp.c.orig	2020-01-07 11:06:41.960834648 +0000
+++ src/bin/jp2/convertbmp.c
@@ -632,12 +632,18 @@ static OPJ_BOOL bmp_read_rle4_data(FILE*
     while (y < height) {
         int c = getc(IN);
         if (c == EOF) {
-            break;
+            return OPJ_FALSE;
         }
 
         if (c) { /* encoded mode */
-            int j;
-            OPJ_UINT8 c1 = (OPJ_UINT8)getc(IN);
+            int j, c1_int;
+            OPJ_UINT8 c1;
+
+            c1_int = getc(IN);
+            if (c1_int == EOF) {
+                return OPJ_FALSE;
+            }
+            c1 = (OPJ_UINT8)c1_int;
 
             for (j = 0; (j < c) && (x < width) &&
                     ((OPJ_SIZE_T)pix < (OPJ_SIZE_T)beyond); j++, x++, pix++) {
@@ -646,7 +652,7 @@ static OPJ_BOOL bmp_read_rle4_data(FILE*
         } else { /* absolute mode */
             c = getc(IN);
             if (c == EOF) {
-                break;
+                return OPJ_FALSE;
             }
 
             if (c == 0x00) { /* EOL */
@@ -657,8 +663,14 @@ static OPJ_BOOL bmp_read_rle4_data(FILE*
                 break;
             } else if (c == 0x02) { /* MOVE by dxdy */
                 c = getc(IN);
+                if (c == EOF) {
+                    return OPJ_FALSE;
+                }
                 x += (OPJ_UINT32)c;
                 c = getc(IN);
+                if (c == EOF) {
+                    return OPJ_FALSE;
+                }
                 y += (OPJ_UINT32)c;
                 pix = pData + y * stride + x;
             } else { /* 03 .. 255 : absolute mode */
@@ -668,12 +680,20 @@ static OPJ_BOOL bmp_read_rle4_data(FILE*
                 for (j = 0; (j < c) && (x < width) &&
                         ((OPJ_SIZE_T)pix < (OPJ_SIZE_T)beyond); j++, x++, pix++) {
                     if ((j & 1) == 0) {
-                        c1 = (OPJ_UINT8)getc(IN);
+                        int c1_int;
+			c1_int = getc(IN);
+			if (c1_int == EOF) {
+			    return OPJ_FALSE;
+			}
+			c1 = (OPJ_UINT8)c1_int;
                     }
                     *pix = (OPJ_UINT8)((j & 1) ? (c1 & 0x0fU) : ((c1 >> 4) & 0x0fU));
                 }
                 if (((c & 3) == 1) || ((c & 3) == 2)) { /* skip padding byte */
-                    getc(IN);
+                    c = getc(IN);
+		    if (c == EOF) {
+			return OPJ_FALSE;
+		    }
                 }
             }
         }
