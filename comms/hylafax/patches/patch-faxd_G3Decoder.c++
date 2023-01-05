$NetBSD: patch-faxd_G3Decoder.c++,v 1.1 2023/01/05 14:30:13 wiz Exp $

Copy internal code from tiff 4.4 that was removed in 4.5.

--- faxd/G3Decoder.c++.orig	2018-09-18 18:51:17.000000000 +0000
+++ faxd/G3Decoder.c++
@@ -87,6 +87,109 @@
     }									\
 } while (0)
 
+/* taken from tiff-4.4.0/libtiff/tif_fax3.c */
+#define isAligned(p,t) ((((size_t)(p)) & (sizeof (t)-1)) == 0)
+# define FILL(n, cp)                              \
+    for (int32_t ifill = 0; ifill < (n); ++ifill) \
+    {                                             \
+        (cp)[ifill] = 0xff;                       \
+    }                                             \
+    (cp) += (n);
+
+# define ZERO(n, cp)                              \
+    for (int32_t izero = 0; izero < (n); ++izero) \
+    {                                             \
+        (cp)[izero] = 0;                          \
+    }                                             \
+    (cp) += (n);
+
+void shopliftedfrom_TIFFFax3fillruns(unsigned char* buf, tiff_runlen_t* runs, tiff_runlen_t* erun, tiff_runlen_t lastx)
+{
+	static const unsigned char _fillmasks[] =
+	    { 0x00, 0x80, 0xc0, 0xe0, 0xf0, 0xf8, 0xfc, 0xfe, 0xff };
+	unsigned char* cp;
+	uint32_t x, bx, run;
+	int32_t n, nw;
+	int64_t* lp;
+
+	if ((erun-runs)&1)
+	    *erun++ = 0;
+	x = 0;
+	for (; runs < erun; runs += 2) {
+	    run = runs[0];
+	    if (x+run > lastx || run > lastx )
+		run = runs[0] = (uint32_t) (lastx - x);
+	    if (run) {
+		cp = buf + (x>>3);
+		bx = x&7;
+		if (run > 8-bx) {
+		    if (bx) {			/* align to byte boundary */
+			*cp++ &= 0xff << (8-bx);
+			run -= 8-bx;
+		    }
+		    if( (n = run >> 3) != 0 ) {	/* multiple bytes to fill */
+			if ((n/sizeof (int64_t)) > 1) {
+			    /*
+			     * Align to int64_tword boundary and fill.
+			     */
+			    for (; n && !isAligned(cp, int64_t); n--)
+				    *cp++ = 0x00;
+			    lp = (int64_t*) cp;
+			    nw = (int32_t)(n / sizeof (int64_t));
+			    n -= nw * sizeof (int64_t);
+			    do {
+				    *lp++ = 0L;
+			    } while (--nw);
+			    cp = (unsigned char*) lp;
+			}
+			ZERO(n, cp);
+			run &= 7;
+		    }
+		    if (run)
+			cp[0] &= 0xff >> run;
+		} else
+		    cp[0] &= ~(_fillmasks[run]>>bx);
+		x += runs[0];
+	    }
+	    run = runs[1];
+	    if (x+run > lastx || run > lastx )
+		run = runs[1] = lastx - x;
+	    if (run) {
+		cp = buf + (x>>3);
+		bx = x&7;
+		if (run > 8-bx) {
+		    if (bx) {			/* align to byte boundary */
+			*cp++ |= 0xff >> bx;
+			run -= 8-bx;
+		    }
+		    if( (n = run>>3) != 0 ) {	/* multiple bytes to fill */
+			if ((n/sizeof (int64_t)) > 1) {
+			    /*
+			     * Align to int64_t boundary and fill.
+			     */
+			    for (; n && !isAligned(cp, int64_t); n--)
+				*cp++ = 0xff;
+			    lp = (int64_t*) cp;
+			    nw = (int32_t)(n / sizeof (int64_t));
+			    n -= nw * sizeof (int64_t);
+			    do {
+				*lp++ = -1L;
+			    } while (--nw);
+			    cp = (unsigned char*) lp;
+			}
+			FILL(n, cp);
+			run &= 7;
+		    }
+                    /* Explicit 0xff masking to make icc -check=conversions happy */
+		    if (run)
+			cp[0] = (unsigned char)((cp[0] | (0xff00 >> run))&0xff);
+		} else
+		    cp[0] |= _fillmasks[run]>>bx;
+		x += runs[1];
+	    }
+	}
+	assert(x == lastx);
+}
 #include "tif_fax3.h"
 
 G3Decoder::G3Decoder() {}
@@ -239,7 +342,7 @@ G3Decoder::decodeRow(void* scanline, u_i
     if (!nullrow)
 	RTCrun = 0;
     if (scanline)
-	_TIFFFax3fillruns((u_char*) scanline, thisrun, pa, lastx);
+	shopliftedfrom_TIFFFax3fillruns((u_char*) scanline, thisrun, pa, lastx);
     if (is2D) {
 	SETVAL(0);			// imaginary change for reference
 	SWAP(tiff_runlen_t*, curruns, refruns);
