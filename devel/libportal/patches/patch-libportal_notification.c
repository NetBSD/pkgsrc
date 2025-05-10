$NetBSD: patch-libportal_notification.c,v 1.1 2025/05/10 12:26:32 tnn Exp $

NetBSD 9 does not have memfd_create(2), so just fail the call.

--- libportal/notification.c.orig	2025-05-09 21:03:04.457028567 +0000
+++ libportal/notification.c
@@ -82,7 +82,12 @@ bytes_to_memfd (const gchar  *name,
   gpointer shm;
   gsize bytes_len;
 
+#ifdef MFD_ALLOW_SEALING
   fd = memfd_create (name, MFD_ALLOW_SEALING);
+#else
+  fd = -1;
+  errno = ENOSYS;
+#endif
   if (fd == -1)
     {
       int saved_errno = errno;
@@ -328,7 +333,12 @@ parse_media (GVariant            *media,
         {
           g_autofd int fd = -1;
 
+#ifdef MFD_ALLOW_SEALING
           fd = memfd_create ("notification-media", MFD_ALLOW_SEALING);
+#else
+          fd = -1;
+          errno = ENOSYS;
+#endif
           if (fd == -1)
             {
               int saved_errno = errno;
