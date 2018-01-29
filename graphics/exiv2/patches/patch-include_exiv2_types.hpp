$NetBSD: patch-include_exiv2_types.hpp,v 1.1 2018/01/29 09:58:34 jperkin Exp $

Remove bogus forward declaration.

--- include/exiv2/types.hpp.orig	2015-06-08 14:39:59.000000000 +0000
+++ include/exiv2/types.hpp
@@ -78,7 +78,6 @@ typedef __int64          int64_t;
 
 // *****************************************************************************
 // forward declarations
-struct tm;
 
 // *****************************************************************************
 // namespace extensions
