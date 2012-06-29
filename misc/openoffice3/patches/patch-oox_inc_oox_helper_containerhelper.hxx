$NetBSD: patch-oox_inc_oox_helper_containerhelper.hxx,v 1.1 2012/06/29 12:36:39 joerg Exp $

--- oox/inc/oox/helper/containerhelper.hxx.orig	2012-06-23 17:25:25.000000000 +0000
+++ oox/inc/oox/helper/containerhelper.hxx
@@ -189,7 +189,7 @@ private:
 
     inline const mapped_type* getRef( key_type nKey ) const
                         {
-                            typename container_type::const_iterator aIt = find( nKey );
+                            typename container_type::const_iterator aIt = this->find( nKey );
                             return (aIt == this->end()) ? 0 : &aIt->second;
                         }
 };
