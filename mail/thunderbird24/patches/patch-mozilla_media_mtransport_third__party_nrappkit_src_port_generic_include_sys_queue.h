$NetBSD: patch-mozilla_media_mtransport_third__party_nrappkit_src_port_generic_include_sys_queue.h,v 1.1 2014/07/27 05:36:07 ryoon Exp $

--- mozilla/media/mtransport/third_party/nrappkit/src/port/generic/include/sys/queue.h.orig	2013-10-23 22:09:11.000000000 +0000
+++ mozilla/media/mtransport/third_party/nrappkit/src/port/generic/include/sys/queue.h
@@ -33,7 +33,7 @@
 #ifndef _SYS_QUEUE_H_
 #define	_SYS_QUEUE_H_
 
-#ifndef DARWIN
+#if !defined(__FreeBSD__) && !defined(DARWIN)
 #include <stddef.h>
 #define __offsetof offsetof
 #endif
