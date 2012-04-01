$NetBSD: patch-lib_warmux_action_action.cpp,v 1.1 2012/04/01 14:41:17 wiz Exp $

Cast away some constness for clang-3.1.

--- lib/warmux/action/action.cpp.orig	2011-01-20 15:53:53.000000000 +0000
+++ lib/warmux/action/action.cpp
@@ -73,16 +73,16 @@ Action::Action(const char *buffer, Dista
 
   var.clear();
   buffer += 4; // skip the buffer len
-  m_type = (Action_t)SDLNet_Read32(buffer);
+  m_type = (Action_t)SDLNet_Read32((char*)buffer);
   buffer += 4;
-  m_timestamp = (uint)SDLNet_Read32(buffer);
+  m_timestamp = (uint)SDLNet_Read32((char*)buffer);
   buffer += 4;
-  int m_length = SDLNet_Read32(buffer);
+  int m_length = SDLNet_Read32((char*)buffer);
   buffer += 4;
 
   for(int i=0; i < m_length; i++)
   {
-    uint32_t val = SDLNet_Read32(buffer);
+    uint32_t val = SDLNet_Read32((char*)buffer);
     var.push_back(val);
     buffer += 4;
   }
