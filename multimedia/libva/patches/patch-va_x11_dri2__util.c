$NetBSD: patch-va_x11_dri2__util.c,v 1.1 2023/02/11 23:37:35 ryoon Exp $

--- va/x11/dri2_util.c.orig	2023-01-10 02:22:08.000000000 +0000
+++ va/x11/dri2_util.c
@@ -178,9 +178,11 @@ va_isRenderNodeFd(int fd)
     struct stat st;
     char *name;
 
+#if !defined(__NetBSD__)
     /* Check by device node */
     if (fstat(fd, &st) == 0)
         return S_ISCHR(st.st_mode) && (st.st_rdev & 0x80);
+#endif
 
     /* Check by device name */
     name = drmGetDeviceNameFromFd(fd);
