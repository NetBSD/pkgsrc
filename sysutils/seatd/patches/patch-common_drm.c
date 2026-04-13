$NetBSD: patch-common_drm.c,v 1.1 2026/04/13 15:49:39 kikadf Exp $

* On NetBSD the setversion ioctl sets the busid, so without
  setversion getunique will return with empty string, and
  drmParseSubsystemType fails with -EINVAL 

--- common/drm.c.orig	2024-10-30 19:43:26.000000000 +0000
+++ common/drm.c
@@ -9,12 +9,41 @@
 #define DRM_IO(nr)            _IO(DRM_IOCTL_BASE, nr)
 #define DRM_IOCTL_SET_MASTER  DRM_IO(0x1e)
 #define DRM_IOCTL_DROP_MASTER DRM_IO(0x1f)
+#if defined(__NetBSD__)
+#include <errno.h>
+#include "log.h"
+struct drm_set_version {
+	int drm_di_major;
+	int drm_di_minor;
+	int drm_dd_major;
+	int drm_dd_minor;
+};
+#define DRM_IOWR(nr,type)     _IOWR(DRM_IOCTL_BASE,nr,type)
+#define DRM_IOCTL_SET_VERSION DRM_IOWR(0x07, struct drm_set_version)
+#endif
 
 #define STRLEN(s)                 ((sizeof(s) / sizeof(s[0])) - 1)
 #define STR_HAS_PREFIX(prefix, s) (strncmp(prefix, s, STRLEN(prefix)) == 0)
 
 int drm_set_master(int fd) {
+#if defined(__NetBSD__)
+	int ret;
+	struct drm_set_version sv;
+
+	if ((ret = ioctl(fd, DRM_IOCTL_SET_MASTER, 0)) == 0) {
+		sv.drm_di_major = 1;
+		sv.drm_di_minor = 4;
+		sv.drm_dd_major = -1;
+		sv.drm_dd_minor = -1;
+		if (ioctl(fd, DRM_IOCTL_SET_VERSION, &sv)) {
+			log_errorf("DRM_IOCTL_SET_VERSION failed: %s", strerror(errno));
+		}
+	}
+
+	return ret;
+#else
 	return ioctl(fd, DRM_IOCTL_SET_MASTER, 0);
+#endif
 }
 
 int drm_drop_master(int fd) {
