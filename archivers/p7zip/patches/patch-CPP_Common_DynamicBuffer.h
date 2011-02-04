$NetBSD: patch-CPP_Common_DynamicBuffer.h,v 1.1 2011/02/04 21:08:21 adam Exp $

--- work/p7zip_9.13//CPP/Common/DynamicBuffer.h.orig	2011-02-04 21:00:13.000000000 +0000
+++ work/p7zip_9.13//CPP/Common/DynamicBuffer.h
@@ -17,7 +17,7 @@ template <class T> class CDynamicBuffer:
     else
       delta = 4;
     delta = MyMax(delta, size);
-    SetCapacity(this->_capacity + delta);
+    this->SetCapacity(this->_capacity + delta);
   }
 public:
   CDynamicBuffer(): CBuffer<T>() {};
