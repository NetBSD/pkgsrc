$NetBSD: patch-lib_warmux_action_action.cpp,v 1.2 2021/01/27 12:13:43 triaxx Exp $

Cast away some constness for clang-3.1.

--- lib/warmux/action/action.cpp.orig	2011-04-28 19:03:14.000000000 +0000
+++ lib/warmux/action/action.cpp
@@ -85,7 +85,7 @@ Action::Action(const char *buffer, Dista
 {
   m_creator = _creator;
 
-  m_header.len = SDLNet_Read32(buffer);
+  m_header.len = SDLNet_Read32((char*)buffer);
   ASSERT(m_header.len >= sizeof(Header));
   buffer += 4;
   // All of the following could be skipped for the actions we now,
