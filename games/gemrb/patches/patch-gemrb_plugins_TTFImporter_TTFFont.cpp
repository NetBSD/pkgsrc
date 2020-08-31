$NetBSD: patch-gemrb_plugins_TTFImporter_TTFFont.cpp,v 1.1 2020/08/31 12:46:21 nia Exp $

Deal with old NetBSD/SunOS style iconv.

--- gemrb/plugins/TTFImporter/TTFFont.cpp.orig	2020-08-23 18:32:26.000000000 +0000
+++ gemrb/plugins/TTFImporter/TTFFont.cpp
@@ -28,6 +28,14 @@
 #if HAVE_ICONV
 #include <iconv.h>
 #include <errno.h>
+#if defined(__NetBSD__)
+#include <sys/param.h>
+#if __NetBSD_Prereq__(9,99,17)
+#define NETBSD_POSIX_ICONV 1
+#else
+#define NETBSD_POSIX_ICONV 0
+#endif /* __NetBSD_Prereq__(9,99,17) */
+#endif /* defined(__NetBSD__) */
 #endif
 
 namespace GemRB {
@@ -50,7 +58,11 @@ const Glyph& TTFFont::GetGlyph(ieWord ch
 		// TODO: make this work on BE systems
 		// TODO: maybe we want to work with non-unicode fonts?
 		iconv_t cd = iconv_open("UTF-16LE", core->TLKEncoding.encoding.c_str());
+#if (defined(__NetBSD__) && !NETBSD_POSIX_ICONV) || defined(__sun)
+		size_t ret = iconv(cd, (const char **)&oldchar, &in, &newchar, &out);
+#else
 		size_t ret = iconv(cd, &oldchar, &in, &newchar, &out);
+#endif
 
 		if (ret != GEM_OK) {
 			Log(ERROR, "FONT", "iconv error: %d", errno);
