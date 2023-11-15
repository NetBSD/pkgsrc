$NetBSD: patch-gemrb_plugins_TTFImporter_TTFFont.cpp,v 1.4 2023/11/15 16:30:13 nia Exp $

Deal with old NetBSD/SunOS style iconv.

--- gemrb/plugins/TTFImporter/TTFFont.cpp.orig	2023-07-08 08:54:22.000000000 +0000
+++ gemrb/plugins/TTFImporter/TTFFont.cpp
@@ -29,6 +29,15 @@
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
@@ -40,7 +49,11 @@ const Glyph& TTFFont::AliasBlank(ieWord 
 const Glyph& TTFFont::GetGlyph(ieWord chr) const
 {
 	if (!core->TLKEncoding.multibyte) {
+#if (defined(__NetBSD__) && !NETBSD_POSIX_ICONV) || defined(__sun)
+		const char* oldchar = (const char*)&chr;
+#else
 		char* oldchar = (char*)&chr;
+#endif
 		ieWord unicodeChr = 0;
 		char* newchar = (char*)&unicodeChr;
 		size_t in = (core->TLKEncoding.widechar) ? 2 : 1;
