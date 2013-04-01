$NetBSD: patch-sc_source_filter_inc_ftools.hxx,v 1.1 2013/04/01 12:19:14 joerg Exp $

--- sc/source/filter/inc/ftools.hxx.orig	2013-03-30 20:20:33.000000000 +0000
+++ sc/source/filter/inc/ftools.hxx
@@ -247,14 +247,14 @@ public:
     /** Returns true, if the object accossiated to the passed key exists. */
     inline bool         has( key_type nKey ) const
                         {
-                            typename map_type::const_iterator aIt = find( nKey );
+                            typename map_type::const_iterator aIt = this->find( nKey );
                             return (aIt != this->end()) && aIt->second.is();
                         }
 
     /** Returns a reference to the object accossiated to the passed key, or 0 on error. */
     inline ref_type     get( key_type nKey ) const
                         {
-                            typename map_type::const_iterator aIt = find( nKey );
+                            typename map_type::const_iterator aIt = this->find( nKey );
                             if( aIt != this->end() ) return aIt->second;
                             return ref_type();
                         }
