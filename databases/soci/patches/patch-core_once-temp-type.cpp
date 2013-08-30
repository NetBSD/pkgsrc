$NetBSD: patch-core_once-temp-type.cpp,v 1.1 2013/08/30 10:19:37 joerg Exp $

--- core/once-temp-type.cpp.orig	2013-08-30 00:17:03.209692967 +0000
+++ core/once-temp-type.cpp
@@ -35,7 +35,7 @@ once_temp_type & once_temp_type::operato
     return *this;
 }
 
-once_temp_type::~once_temp_type()
+once_temp_type::~once_temp_type() SOCI_ONCE_TEMP_TYPE_NOEXCEPT
 {
     rcst_->dec_ref();
 }
