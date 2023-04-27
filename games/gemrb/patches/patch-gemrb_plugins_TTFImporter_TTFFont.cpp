$NetBSD: patch-gemrb_plugins_TTFImporter_TTFFont.cpp,v 1.2 2023/04/27 18:50:59 yhardy Exp $

Deal with old NetBSD/SunOS style iconv.

--- gemrb/plugins/TTFImporter/TTFFont.cpp.orig	2022-08-29 19:10:39.000000000 +0000
+++ gemrb/plugins/TTFImporter/TTFFont.cpp
@@ -28,6 +28,15 @@
 #include <iconv.h>
 #include <cerrno>
 
+#if defined(__NetBSD__)
+#include <sys/param.h>
+#if __NetBSD_Prereq__(9,99,17)
+#define NETBSD_POSIX_ICONV 1
+#else
+#define NETBSD_POSIX_ICONV 0
+#endif /* __NetBSD_Prereq__(9,99,17) */
+#endif /* defined(__NetBSD__) */
+
 namespace GemRB {
 
 const Glyph& TTFFont::AliasBlank(ieWord chr) const
@@ -48,7 +57,11 @@ const Glyph& TTFFont::GetGlyph(ieWord ch
 		// TODO: make this work on BE systems
 		// TODO: maybe we want to work with non-unicode fonts?
 		iconv_t cd = iconv_open("UTF-16LE", core->TLKEncoding.encoding.c_str());
+#if (defined(__NetBSD__) && !NETBSD_POSIX_ICONV) || defined(__sun)
+		size_t ret = iconv(cd, (const char **)&oldchar, &in, &newchar, &out);
+#else
 		size_t ret = iconv(cd, &oldchar, &in, &newchar, &out);
+#endif
 
 		if (ret != GEM_OK) {
 			Log(ERROR, "FONT", "iconv error: {}", errno);
