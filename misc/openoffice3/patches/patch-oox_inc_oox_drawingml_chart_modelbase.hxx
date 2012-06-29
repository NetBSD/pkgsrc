$NetBSD: patch-oox_inc_oox_drawingml_chart_modelbase.hxx,v 1.1 2012/06/29 12:36:39 joerg Exp $

--- oox/inc/oox/drawingml/chart/modelbase.hxx.orig	2012-06-23 17:29:44.000000000 +0000
+++ oox/inc/oox/drawingml/chart/modelbase.hxx
@@ -52,13 +52,13 @@ public:
 
     inline bool         is() const { return this->get() != 0; }
 
-    inline ModelType&   create() { reset( new ModelType ); return **this; }
+    inline ModelType&   create() { this->reset( new ModelType ); return **this; }
     template< typename Param1Type >
-    inline ModelType&   create( const Param1Type& rParam1 ) { reset( new ModelType( rParam1 ) ); return **this; }
+    inline ModelType&   create( const Param1Type& rParam1 ) { this->reset( new ModelType( rParam1 ) ); return **this; }
 
-    inline ModelType&   getOrCreate() { if( !*this ) reset( new ModelType ); return **this; }
+    inline ModelType&   getOrCreate() { if( !*this ) this->reset( new ModelType ); return **this; }
     template< typename Param1Type >
-    inline ModelType&   getOrCreate( const Param1Type& rParam1 ) { if( !*this ) reset( new ModelType( rParam1 ) ); return **this; }
+    inline ModelType&   getOrCreate( const Param1Type& rParam1 ) { if( !*this ) this->reset( new ModelType( rParam1 ) ); return **this; }
 };
 
 // ============================================================================
