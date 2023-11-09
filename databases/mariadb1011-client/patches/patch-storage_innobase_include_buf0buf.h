$NetBSD: patch-storage_innobase_include_buf0buf.h,v 1.1 2023/11/09 19:26:32 nia Exp $

SunOS build fix.

buf0buf.h:664:13: error: invalid conversion from 'byte*' {aka 'unsigned char*'} to 'caddr_t' {aka 'char*'} [-fpermissive]

--- storage/innobase/include/buf0buf.h.orig	2023-08-11 06:39:42.000000000 +0000
+++ storage/innobase/include/buf0buf.h
@@ -659,7 +659,7 @@ public:
   void set_os_unused()
   {
     MEM_NOACCESS(frame, srv_page_size);
-#ifdef MADV_FREE
+#if defined(MADV_FREE) && !defined(__sun)
     madvise(frame, srv_page_size, MADV_FREE);
 #endif
   }
