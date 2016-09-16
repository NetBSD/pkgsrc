$NetBSD: patch-include_my__global.h,v 1.1 2016/09/16 06:49:11 adam Exp $

--- include/my_global.h.orig	2016-03-28 18:06:12.000000000 +0000
+++ include/my_global.h
@@ -145,6 +145,15 @@ static inline void sleep(unsigned long s
 #define default_shared_memory_base_name "MYSQL"
 #endif /* _WIN32*/
 
+#if defined(__sgi) && !defined(SHUT_RDWR)
+
+/*
+  IRIX 5 does not define SHUT_RDWR
+*/
+
+#define SHUT_RDWR 2
+#endif
+
 /**
   Cast a member of a structure to the structure that contains it.
 
