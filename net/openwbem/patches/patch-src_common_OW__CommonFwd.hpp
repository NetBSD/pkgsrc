$NetBSD: patch-src_common_OW__CommonFwd.hpp,v 1.1.24.1 2016/05/23 05:06:09 bsiegert Exp $

--- src/common/OW_CommonFwd.hpp.orig	2005-11-04 22:34:12.000000000 +0000
+++ src/common/OW_CommonFwd.hpp
@@ -38,19 +38,8 @@
 #include "OW_ArrayFwd.hpp"
 #include "OW_IntrusiveReference.hpp"
 
-// Yeah I know this is forbidden by the standard, but what am I gonna do?  #include <algorithm> ? I think not.
-// If it causes a problem on some compiler, just #ifdef a fix in.
-#ifdef OW_WIN32
-namespace std
-{
-	template <typename T> struct less;
-}
-#else
-namespace std
-{
-	template <typename T> class less;
-}
-#endif
+#include <algorithm>
+#include <functional>
 
 namespace OW_NAMESPACE
 {
