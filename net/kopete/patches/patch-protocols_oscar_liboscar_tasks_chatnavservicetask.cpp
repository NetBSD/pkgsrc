$NetBSD: patch-protocols_oscar_liboscar_tasks_chatnavservicetask.cpp,v 1.1 2017/06/17 19:44:22 joerg Exp $

--- protocols/oscar/liboscar/tasks/chatnavservicetask.cpp.orig	2017-06-09 12:28:44.075531593 +0000
+++ protocols/oscar/liboscar/tasks/chatnavservicetask.cpp
@@ -105,7 +105,7 @@ bool ChatNavServiceTask::take( Transfer*
 void ChatNavServiceTask::onGo()
 {
     FLAP f =  { 0x02, 0, 0x00 };
-    SNAC s = { 0x000D, m_type, 0x0000, client()->snacSequence() };
+    SNAC s = { 0x000D, static_cast<Oscar::WORD>(m_type), 0x0000, client()->snacSequence() };
     Buffer* b = new Buffer();
 
     Transfer* t = createTransfer( f, s, b );
