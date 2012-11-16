$NetBSD: patch-decompiler_refcounted.h,v 1.1 2012/11/16 00:51:36 joerg Exp $

--- decompiler/refcounted.h.orig	2012-11-15 15:46:47.000000000 +0000
+++ decompiler/refcounted.h
@@ -25,10 +25,8 @@
 
 class RefCounted;
 
-namespace boost {
 inline void intrusive_ptr_add_ref(RefCounted *p);
 inline void intrusive_ptr_release(RefCounted *p);
-} // End of namespace boost
 
 /**
  * Provides a base implementation of reference counting for use with boost::intrusive_ptr.
@@ -36,16 +34,14 @@ inline void intrusive_ptr_release(RefCou
 class RefCounted {
 private:
 	long _refCount; ///< Reference count used for boost::intrusive_ptr.
-	friend void ::boost::intrusive_ptr_add_ref(RefCounted *p); ///< Allow access by reference counting methods in boost namespace.
-	friend void ::boost::intrusive_ptr_release(RefCounted *p); ///< Allow access by reference counting methods in boost namespace.
+	friend void ::intrusive_ptr_add_ref(RefCounted *p); ///< Allow access by reference counting methods in boost namespace.
+	friend void ::intrusive_ptr_release(RefCounted *p); ///< Allow access by reference counting methods in boost namespace.
 
 protected:
 	RefCounted() : _refCount(0) { }
 	virtual ~RefCounted() { }
 };
 
-namespace boost {
-
 /**
  * Add a reference to a pointer.
  */
@@ -61,6 +57,4 @@ inline void intrusive_ptr_release(RefCou
 		delete p;
 }
 
-} // End of namespace boost
-
 #endif
