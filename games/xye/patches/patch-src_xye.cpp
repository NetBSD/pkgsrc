$NetBSD: patch-src_xye.cpp,v 1.1 2025/02/09 08:45:39 triaxx Exp $

Avoid ambiguity with std::lock.

--- src/xye.cpp.orig	2025-02-09 07:33:16.280947404 +0000
+++ src/xye.cpp
@@ -7806,20 +7806,20 @@ bool key::GetXyesKeys(unsigned int &yl,u
 
 /**Start Class Lock**/
 
-lock::lock(square* sq, blockcolor color)
+xye_lock::xye_lock(square* sq, blockcolor color)
 {
     type=OT_LOCK;
     c=color;
     ObjectConstruct(sq);
 }
-void lock::Draw(unsigned int x, unsigned int y)
+void xye_lock::Draw(unsigned int x, unsigned int y)
 {
     Drawer D(game::sprites,sz*7,sz*4,sz,sz);
     D.SetColors(options::BKColor[c],255);
     D.Draw(game::screen,x,y);
 }
 
-bool lock::trypush(edir dir,obj* pusher)
+bool xye_lock::trypush(edir dir,obj* pusher)
 {
     if ((pusher->GetType()==OT_XYE) && (key::GotKey(c)))
     {
@@ -7831,9 +7831,9 @@ bool lock::trypush(edir dir,obj* pusher)
     return false;
 }
 
-bool lock::HasRoundCorner(roundcorner rnc) { return false; }
+bool xye_lock::HasRoundCorner(roundcorner rnc) { return false; }
 
-inline bool lock::HasBlockColor(blockcolor bc) { return false; }
+inline bool xye_lock::HasBlockColor(blockcolor bc) { return false; }
 
 
 /**End Class Lock**/
