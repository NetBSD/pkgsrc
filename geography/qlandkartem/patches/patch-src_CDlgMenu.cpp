$NetBSD: patch-src_CDlgMenu.cpp,v 1.1 2017/09/09 23:57:36 dholland Exp $

Another day, another C++ syntax change.

--- src/CDlgMenu.cpp~	2009-10-13 17:50:05.000000000 +0000
+++ src/CDlgMenu.cpp
@@ -41,7 +41,7 @@
 #define _MKSTR(x)      _MKSTR_1(x)
 #endif
 
-#define VER_STR       _MKSTR(VER_MAJOR)"."_MKSTR(VER_MINOR)"."_MKSTR(VER_STEP)
+#define VER_STR       _MKSTR(VER_MAJOR) "." _MKSTR(VER_MINOR) "." _MKSTR(VER_STEP)
 
 CDlgMenu * CDlgMenu::m_self = 0;
 
