$NetBSD: patch-src_utils_os__config__init.c,v 1.1 2021/09/17 00:10:21 nia Exp $

Support NetBSD.

--- src/utils/os_config_init.c.orig	2020-09-10 16:38:49.000000000 +0000
+++ src/utils/os_config_init.c
@@ -71,6 +71,10 @@
 #define TEST_MODULE		"gm_"
 #endif
 
+#if defined(__NetBSD__)
+#include <sys/sysctl.h>
+#endif
+
 #endif
 
 #if !defined(GPAC_STATIC_MODULES) && !defined(GPAC_MP4BOX_MINI)
@@ -295,6 +299,10 @@ static Bool get_default_install_path(cha
 #if (defined(__DARWIN__) || defined(__APPLE__) || defined(GPAC_CONFIG_LINUX))
 	u32 size;
 #endif
+#if defined(__NetBSD__)
+	int mib[] = { CTL_KERN, KERN_PROC_ARGS, -1, KERN_PROC_PATHNAME };
+	size_t size;
+#endif
 
 	/*on OSX, Linux & co, user home is where we store the cfg file*/
 	if (path_type==GF_PATH_CFG) {
@@ -342,6 +350,15 @@ static Bool get_default_install_path(cha
 			return 1;
 		}
 
+#elif defined(__NetBSD__)
+		size = sizeof(app_path);
+		if (sysctl(mib, 4, app_path, &size, NULL, 0) != -1) {
+			realpath(app_path, file_path);
+			sep = strrchr(file_path, '/');
+			if (sep) sep[0] = 0;
+			return 1;
+		}
+
 #elif defined(GPAC_CONFIG_LINUX)
 		size = readlink("/proc/self/exe", file_path, GF_MAX_PATH-1);
 		if (size>0) {
