$NetBSD: patch-CPP_Common_DynamicBuffer.h,v 1.2 2011/02/04 22:46:33 wiz Exp $

--- CPP/Common/DynamicBuffer.h.orig	2011-02-04 21:00:13.000000000 +0000
+++ CPP/Common/DynamicBuffer.h
@@ -17,7 +17,7 @@ template <class T> class CDynamicBuffer:
     else
       delta = 4;
     delta = MyMax(delta, size);
-    SetCapacity(this->_capacity + delta);
+    this->SetCapacity(this->_capacity + delta);
   }
 public:
   CDynamicBuffer(): CBuffer<T>() {};
