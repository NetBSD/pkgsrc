$NetBSD: patch-include_tool_tool_interactive.h,v 1.2 2019/06/08 11:04:28 rillig Exp $

Fix for newer boost, from upstream developement branch

--- include/tool/tool_interactive.h.orig	2016-09-03 22:47:50.000000000 +0200
+++ include/tool/tool_interactive.h	2016-09-07 19:03:09.000000000 +0200
@@ -3,6 +3,7 @@
  *
  * Copyright (C) 2013 CERN
  * @author Tomasz Wlostowski <tomasz.wlostowski@cern.ch>
+ * Copyright (C) 2016 KiCad Developers, see AUTHORS.txt for contributors.
  *
  * This program is free software; you can redistribute it and/or
  * modify it under the terms of the GNU General Public License
@@ -113,7 +114,7 @@
 void TOOL_INTERACTIVE::Go( int (T::* aStateFunc)( const TOOL_EVENT& ),
                            const TOOL_EVENT_LIST& aConditions )
 {
-    TOOL_STATE_FUNC sptr( static_cast<T*>( this ), aStateFunc );
+    TOOL_STATE_FUNC sptr = std::bind( aStateFunc, static_cast<T*>( this ), std::placeholders::_1 );
 
     goInternal( sptr, aConditions );
 }
