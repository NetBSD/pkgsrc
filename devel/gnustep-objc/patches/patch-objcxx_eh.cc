$NetBSD: patch-objcxx_eh.cc,v 1.1 2020/04/16 09:28:39 manu Exp $

Workaround build failure due to redefinition

--- objcxx_eh.cc.orig	2020-04-14 11:22:03.686048307 +0200
+++ objcxx_eh.cc	2020-04-14 11:22:33.134026599 +0200
@@ -14,8 +14,9 @@
 }
 
 using __cxxabiv1::__class_type_info;
 
+#if 0
 namespace std
 {
 	/**
 	 * std::type_info defined with the GCC ABI.  This may not be exposed in
@@ -47,8 +48,9 @@
 				                const __class_type_info *target,
 				                void **thrown_object) const;
 	};
 }
+#endif
 
 using namespace std;
 
 
