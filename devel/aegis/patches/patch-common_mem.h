$NetBSD: patch-common_mem.h,v 1.1 2022/12/24 23:32:48 wiz Exp $

gcc complains about
./common/mem.h:128:25: warning: dynamic exception specifications are deprecated in C++11 [-Wdeprecated]                                                                                                                                                                               
and later the build breaks.

--- common/mem.h.orig	2009-06-25 16:00:55.000000000 +0000
+++ common/mem.h
@@ -125,7 +125,7 @@ char *dmem_copy_string(const char *file,
 #endif
 
 #if HAVE_HEADER_NEW || HAVE_NEW_H
-#define THROW_BAD_ALLOC throw(std::bad_alloc)
+#define THROW_BAD_ALLOC // throw(std::bad_alloc)
 #else
 #define THROW_BAD_ALLOC
 #endif
