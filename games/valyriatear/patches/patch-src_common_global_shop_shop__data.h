$NetBSD: patch-src_common_global_shop_shop__data.h,v 1.1 2021/04/25 09:10:43 nia Exp $

Add missing header, fixes building with gcc10.

--- src/common/global/shop/shop_data.h.orig	2019-07-29 10:49:37.000000000 +0000
+++ src/common/global/shop/shop_data.h
@@ -12,6 +12,7 @@
 #define __SHOP_DATA_HEADER__
 
 #include <map>
+#include <cstdint>
 
 namespace vt_global {
 
