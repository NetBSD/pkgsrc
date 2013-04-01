$NetBSD: patch-o3tl_inc_o3tl_lazy__update.hxx,v 1.1 2013/04/01 12:19:14 joerg Exp $

--- o3tl/inc/o3tl/lazy_update.hxx.orig	2013-03-30 17:02:03.000000000 +0000
+++ o3tl/inc/o3tl/lazy_update.hxx
@@ -104,13 +104,13 @@ output( myValue.getOutValue() );
 
             void               setInValue( input_type const& rIn ) { Functor::m_bCacheDirty = true; m_aInput = rIn; }
             input_type const&  getInValue()  const                 { return m_aInput; }
-            output_type const& getOutValue() const                 { return implUpdateValue(m_aInput); }
+            output_type const& getOutValue() const                 { return this->implUpdateValue(m_aInput); }
         
             input_type& operator*()  { Functor::m_bCacheDirty = true; return m_aInput;  }
             input_type* operator->() { Functor::m_bCacheDirty = true; return &m_aInput; }
 
-            output_type const& operator*() const  { return implUpdateValue(m_aInput);  }
-            output_type const* operator->() const { return &implUpdateValue(m_aInput); }
+            output_type const& operator*() const  { return this->implUpdateValue(m_aInput);  }
+            output_type const* operator->() const { return &this->implUpdateValue(m_aInput); }
         
         private:
             input_type m_aInput;
