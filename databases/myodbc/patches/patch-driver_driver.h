$NetBSD: patch-driver_driver.h,v 1.1 2022/12/25 08:22:26 wiz Exp $

NetBSD does not provide uselocale().

--- driver/driver.h.orig	2022-09-01 11:59:03.000000000 +0000
+++ driver/driver.h
@@ -252,7 +252,7 @@ extern std::mutex global_fido_mutex;
       _configthreadlocale(loc); \
     }
 
-#elif defined LC_GLOBAL_LOCALE
+#elif defined(LC_GLOBAL_LOCALE) && !defined(__NetBSD__)
   #define DECLARE_LOCALE_HANDLE locale_t nloc;
 
   #define __LOCALE_SET(LOC) \
