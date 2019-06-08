$NetBSD: patch-common_tool_tool_manager.cpp,v 1.2 2019/06/08 11:04:28 rillig Exp $

Fix for newer boost, from upstream developement branch

--- common/tool/tool_manager.cpp.orig	2016-09-03 22:47:46.000000000 +0200
+++ common/tool/tool_manager.cpp	2016-09-07 19:03:09.000000000 +0200
@@ -542,11 +542,11 @@
                     if( st->cofunc )
                         st->Push();
 
+                    st->cofunc = new COROUTINE<int, const TOOL_EVENT&>( tr.second );
+
                     // as the state changes, the transition table has to be set up again
                     st->transitions.clear();
 
-                    st->cofunc = new COROUTINE<int, const TOOL_EVENT&>( tr.second );
-
                     // got match? Run the handler.
                     st->cofunc->Call( aEvent );
 
