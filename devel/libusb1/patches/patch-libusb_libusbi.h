$NetBSD: patch-libusb_libusbi.h,v 1.1 2016/04/09 08:18:58 richard Exp $

prepare SunOS backend support

--- libusb/libusbi.h.orig	2015-09-14 00:36:19.000000000 +0000
+++ libusb/libusbi.h
@@ -493,7 +493,8 @@ int usbi_signal_event(struct libusb_cont
 int usbi_clear_event(struct libusb_context *ctx);
 
 /* Internal abstraction for poll (needs struct usbi_transfer on Windows) */
-#if defined(OS_LINUX) || defined(OS_DARWIN) || defined(OS_OPENBSD) || defined(OS_NETBSD) || defined(OS_HAIKU)
+#if defined(OS_LINUX) || defined(OS_DARWIN) || defined(OS_OPENBSD) || defined(OS_NETBSD) || \
+	defined(OS_HAIKU) || defined(OS_SUNOS)
 #include <unistd.h>
 #include "os/poll_posix.h"
 #elif defined(OS_WINDOWS) || defined(OS_WINCE)
@@ -1091,6 +1092,7 @@ extern const struct usbi_os_backend netb
 extern const struct usbi_os_backend windows_backend;
 extern const struct usbi_os_backend wince_backend;
 extern const struct usbi_os_backend haiku_usb_raw_backend;
+extern const struct usbi_os_backend sunos_backend;
 
 extern struct list_head active_contexts_list;
 extern usbi_mutex_static_t active_contexts_lock;
