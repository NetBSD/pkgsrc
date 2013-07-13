$NetBSD: patch-xen_common_libelf_libelf-private.h,v 1.1 2013/07/13 19:43:21 joerg Exp $

--- xen/common/libelf/libelf-private.h.orig	2013-07-12 18:07:36.000000000 +0000
+++ xen/common/libelf/libelf-private.h
@@ -1,4 +1,4 @@
-#ifndef __LIBELF_PRIVATE_H__
+#ifndef __LIBELF_PRIVATE_H_
 #define __LIBELF_PRIVATE_H_
 
 #ifdef __XEN__
