$NetBSD: patch-gemrb_core_Strings_StringConversion.cpp,v 1.3 2023/11/15 16:30:13 nia Exp $

Deal with old NetBSD/SunOS style iconv.

--- gemrb/core/Strings/StringConversion.cpp.orig	2023-07-08 08:54:22.000000000 +0000
+++ gemrb/core/Strings/StringConversion.cpp
@@ -20,6 +20,15 @@
 
 #include <iconv.h>
 
+#if defined(__NetBSD__)
+#include <sys/param.h>
+#if __NetBSD_Prereq__(9,99,17)
+#define NETBSD_POSIX_ICONV 1
+#else
+#define NETBSD_POSIX_ICONV 0
+#endif /* __NetBSD_Prereq__(9,99,17) */
+#endif /* defined(__NetBSD__) */
+
 #include "ie_types.h"
 #include "Interface.h"
 #include "Logging/Logging.h"
@@ -109,7 +118,11 @@ char* ConvertCharEncoding(const char* st
 	}
 
 
+#if (defined(__NetBSD__) && !NETBSD_POSIX_ICONV) || defined(__sun)
+	const char * in = (const char *) string;
+#else
 	char * in = (char *) string;
+#endif
 	size_t in_len = strlen(string);
 	size_t out_len = (in_len + 1) * 4;
 	size_t out_len_left = out_len;
