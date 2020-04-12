$NetBSD: patch-libs_pbd_pbd_id.h,v 1.1 2020/04/12 19:36:26 joerg Exp $

Ensure operators are defined in the namespace of one of the arguments.

--- libs/pbd/pbd/id.h.orig	2020-04-11 23:41:22.316485469 +0000
+++ libs/pbd/pbd/id.h
@@ -73,8 +73,8 @@ class LIBPBD_API ID {
 	static uint64_t _counter;
 };
 
-}
+LIBPBD_API std::ostream& operator<< (std::ostream& ostr, const ID&);
 
-LIBPBD_API std::ostream& operator<< (std::ostream& ostr, const PBD::ID&);
+}
 
 #endif /* __pbd_id_h__ */
