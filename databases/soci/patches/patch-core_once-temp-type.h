$NetBSD: patch-core_once-temp-type.h,v 1.1 2013/08/30 10:19:37 joerg Exp $

--- core/once-temp-type.h.orig	2013-08-30 00:16:03.749693674 +0000
+++ core/once-temp-type.h
@@ -21,6 +21,12 @@ namespace details
 
 class ref_counted_statement;
 
+#if __cplusplus >= 201103L
+#define SOCI_ONCE_TEMP_TYPE_NOEXCEPT noexcept(false)
+#else
+#define SOCI_ONCE_TEMP_TYPE_NOEXCEPT
+#endif
+
 // this needs to be lightweight and copyable
 class SOCI_DECL once_temp_type
 {
@@ -30,7 +36,7 @@ public:
     once_temp_type(once_temp_type const & o);
     once_temp_type & operator=(once_temp_type const & o);
 
-    ~once_temp_type();
+    ~once_temp_type() SOCI_ONCE_TEMP_TYPE_NOEXCEPT;
 
     template <typename T>
     once_temp_type & operator<<(T const & t)
