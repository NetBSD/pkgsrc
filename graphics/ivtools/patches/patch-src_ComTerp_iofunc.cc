$NetBSD: patch-src_ComTerp_iofunc.cc,v 1.1 2021/03/01 09:48:40 nia Exp $

Fix building without HAVE_ACE:
SocketObj is only defined if HAVE_ACE.

--- src/ComTerp/iofunc.cc.orig	2020-10-10 13:03:09.000000000 +0000
+++ src/ComTerp/iofunc.cc
@@ -441,11 +441,13 @@ void CloseFileFunc::execute() {
     pipeobj->close();
     return;
   }
+#ifdef HAVE_ACE
   if (objv.is_socketobj()) {
     SocketObj *sockobj = (SocketObj*)objv.geta(SocketObj::class_symid());
     sockobj->close();
     return;
   }
+#endif
 }
 
 /*****************************************************************************/
