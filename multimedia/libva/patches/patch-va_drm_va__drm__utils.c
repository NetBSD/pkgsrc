$NetBSD: patch-va_drm_va__drm__utils.c,v 1.1 2022/05/10 14:45:16 ryoon Exp $

* Enable display=drm under NetBSD. Do not use fstat case, but name case.

--- va/drm/va_drm_utils.c.orig	2022-01-28 16:00:00.000000000 +0000
+++ va/drm/va_drm_utils.c
@@ -120,9 +120,11 @@ VA_DRM_IsRenderNodeFd(int fd)
     struct stat st;
     const char *name;
 
+#if !defined(__NetBSD__)
     /* Check by device node */
     if (fstat(fd, &st) == 0)
         return S_ISCHR(st.st_mode) && (st.st_rdev & 0x80);
+#endif
 
     /* Check by device name */
     name = drmGetDeviceNameFromFd(fd);
