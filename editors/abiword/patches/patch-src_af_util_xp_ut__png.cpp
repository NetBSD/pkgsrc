$NetBSD: patch-src_af_util_xp_ut__png.cpp,v 1.1 2018/12/28 22:24:53 gutteridge Exp $

Abiword bug 13827, SVN revision 35369: Fix overflow read in PNG.

--- src/af/util/xp/ut_png.cpp.orig	2013-04-07 13:53:03.000000000 +0000
+++ src/af/util/xp/ut_png.cpp
@@ -28,6 +28,7 @@
 
 #include "ut_assert.h"
 #include "ut_bytebuf.h"
+#include "ut_debugmsg.h"
 
 struct _bb
 {
@@ -40,6 +41,19 @@ static void _png_read(png_structp png_pt
 	struct _bb* p = static_cast<struct _bb*>(png_get_io_ptr(png_ptr));
 	const UT_Byte* pBytes = p->pBB->getPointer(0);
 
+	// make sure that we don't read outside of pBytes
+	if (p->iCurPos >= p->pBB->getLength() - length) {
+		UT_WARNINGMSG(("PNG: Reading past buffer bounds. cur = %u, buflen = %u, length = %lu\n",
+					   p->iCurPos, p->pBB->getLength(), length));
+		length = p->pBB->getLength() - p->iCurPos;
+		if (length == 0) {
+			UT_WARNINGMSG(("PNG: Truncating to ZERO length.\n"));
+			png_error(png_ptr, "Premature end of buffer");
+			return;
+		} else {
+			UT_WARNINGMSG(("PNG: Truncating to %lu.\n", length));
+		}
+	}
 	memcpy(data, pBytes + p->iCurPos, length);
 	p->iCurPos += length;
 }
