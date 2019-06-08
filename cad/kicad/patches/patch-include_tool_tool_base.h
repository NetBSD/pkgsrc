$NetBSD: patch-include_tool_tool_base.h,v 1.2 2019/06/08 11:04:28 rillig Exp $

Fix for newer boost, from upstream developement branch

--- include/tool/tool_base.h.orig	2016-09-03 22:47:50.000000000 +0200
+++ include/tool/tool_base.h	2016-09-07 19:03:09.000000000 +0200
@@ -3,6 +3,7 @@
  *
  * Copyright (C) 2013 CERN
  * @author Tomasz Wlostowski <tomasz.wlostowski@cern.ch>
+ * Copyright (C) 2016 KiCad Developers, see AUTHORS.txt for contributors.
  *
  * This program is free software; you can redistribute it and/or
  * modify it under the terms of the GNU General Public License
@@ -31,7 +32,7 @@
 #include <tool/tool_event.h>
 #include <tool/tool_settings.h>
 
-#include <tool/delegate.h>
+#include <functional>
 
 class EDA_ITEM;
 class TOOL_MANAGER;
@@ -53,7 +54,9 @@
 
 /// Unique identifier for tools
 typedef int TOOL_ID;
-typedef DELEGATE<int, const TOOL_EVENT&> TOOL_STATE_FUNC;
+
+using TOOL_STATE_FUNC = std::function<int(const TOOL_EVENT&)>;
+
 
 /**
  * Class TOOL_BASE
