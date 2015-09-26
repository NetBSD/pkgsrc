$NetBSD: patch-src_loader_loader.c,v 1.2 2015/09/26 08:45:02 tnn Exp $

FreeBSD & DragonFly support for libdevq. From FreeBSD ports(?)

--- src/loader/loader.c.orig	2015-09-10 18:07:21.000000000 +0000
+++ src/loader/loader.c
@@ -70,7 +70,7 @@
 #include <stdarg.h>
 #include <stdio.h>
 #include <string.h>
-#ifdef HAVE_LIBUDEV
+#if defined(HAVE_LIBUDEV) || defined(HAVE_LIBDEVQ)
 #include <assert.h>
 #include <dlfcn.h>
 #include <unistd.h>
@@ -505,6 +505,53 @@ sysfs_get_pci_id_for_fd(int fd, int *ven
 }
 #endif
 
+#if defined(HAVE_LIBDEVQ)
+#include <libdevq.h>
+
+static void *devq_handle = NULL;
+
+static void *
+devq_dlopen_handle(void)
+{
+   if (!devq_handle) {
+      devq_handle = dlopen("libdevq.so.0", RTLD_LOCAL | RTLD_LAZY);
+   }
+
+   return devq_handle;
+}
+
+static void *
+asserted_dlsym(void *dlopen_handle, const char *name)
+{
+   void *result = dlsym(dlopen_handle, name);
+   assert(result);
+   return result;
+}
+
+#define DEVQ_SYMBOL(ret, name, args) \
+   ret (*name) args = asserted_dlsym(devq_dlopen_handle(), #name);
+
+static int
+devq_get_pci_id_from_fd(int fd, int *vendor_id, int *chip_id)
+{
+   int ret;
+   DEVQ_SYMBOL(int, devq_device_get_pciid_from_fd,
+               (int fd, int *vendor_id, int *chip_id));
+
+   *chip_id = -1;
+
+   ret = devq_device_get_pciid_from_fd(fd, vendor_id, chip_id);
+   if (ret < 0) {
+      log_(_LOADER_WARNING, "MESA-LOADER: could not get PCI ID\n");
+      goto out;
+   }
+
+out:
+   return (*chip_id >= 0);
+}
+
+#endif
+
 #if defined(HAVE_LIBDRM)
 /* for i915 */
 #include <i915_drm.h>
@@ -588,6 +635,12 @@ loader_get_pci_id_for_fd(int fd, int *ve
    if (sysfs_get_pci_id_for_fd(fd, vendor_id, chip_id))
       return 1;
 #endif
+
+#if HAVE_LIBDEVQ
+   if (devq_get_pci_id_from_fd(fd, vendor_id, chip_id))
+      return 1;
+#endif
+
 #if HAVE_LIBDRM
    if (drm_get_pci_id_for_fd(fd, vendor_id, chip_id))
       return 1;
